<?
  require_once("includes/common.php");

  $symbol = mysqli_real_escape_string($connection, $_POST["symbol"]);

  $s = lookup($_POST["symbol"]);

    if($s === NULL)
        apologize("Ticket de ação inválido!");

  $result = mysqli_query($connection, "SELECT shares FROM stocks WHERE userId = {$_SESSION["uid"]} AND symbol = '{$symbol}'");
  
  $shares = mysqli_fetch_array($result);

  if($shares["shares"] == 0)
    apologize("Ação não encontrada no banco de dados!");

  $stockPrice = str_replace(",", ".", $s->price);

  $value = $shares["shares"] * $s->price;

  $sql = "INSERT INTO trades(userId, type, symbol, shares, price) VALUES ({$_SESSION["uid"]}, 'SELL', '$symbol', {$shares['shares']}, '$stockPrice')";

  mysqli_query($connection, $sql);

  mysqli_query($connection, "DELETE FROM stocks WHERE userId = {$_SESSION["uid"]} AND symbol = '{$symbol}'");

  mysqli_query($connection, "UPDATE users SET cash = cash + $value WHERE uid = {$_SESSION["uid"]}");

?>

<div style="text-align: center">
  Venda efetuada com sucesso no valor de R$<?= $value ?>!
</div>