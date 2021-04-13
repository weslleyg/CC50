<?
    require_once("includes/common.php");

    $quote = mysqli_real_escape_string($connection, $_POST["symbol"]);
    $amount = mysqli_real_escape_string($connection, $_POST["shares"]);

    if(!preg_match("/^[0-9]*$/", $amount))
      apologize("Quantidade inválida!");

    $s = lookup($quote);

    if($s === NULL)
      apologize("Ticket de ação inválido!");

    $result = mysqli_query($connection, "SELECT cash FROM users WHERE uid = {$_SESSION["uid"]}");
    $row = mysqli_fetch_array($result);

    $total = ($amount * $s->price);

    if($total > $row["cash"])
      apologize("Dinheiro insuficiente!");

    $sql = "INSERT INTO stocks(userId, symbol, shares) VALUES({$_SESSION["uid"]}, '$quote', $amount) 
    ON DUPLICATE KEY UPDATE shares = shares + $amount";

    $insetion = mysqli_query($connection, $sql);

    if($insetion == false)
      apologize("Erro na execução! {$amount}");

    $stockPrice = str_replace(",", ".", $s->price);

    mysqli_query($connection, "INSERT INTO trades(userId, type, symbol, shares, price) VALUES ({$_SESSION["uid"]}, 'BUY', '$quote', $amount, '$stockPrice')");
    mysqli_query($connection, "UPDATE users SET cash = cash - $total WHERE uid = {$_SESSION["uid"]}");
?>

<div style="text-align: center">
 Compra de <?= $s->name ?> efetuada com sucesso no valor de $<?= ($amount * $s->price) ?>.
</div>