<?
  require_once("includes/common.php");

  $symbol = mysqli_real_escape_string($connection, $_POST["symbol"]);

  $s = lookup($_POST["symbol"]);

    if($s === NULL)
        apologize("Ticket de ação inválido!");

  $result = mysqli_query($connection, "SELECT shares FROM stocks WHERE userId = {$_SESSION["uid"]} ORDER BY symbol = $symbol");
  
  $shares = mysqli_fetch_array($result);

  $value = $shares["shares"] * $s->price;

  mysqli_query($connection, "DELETE FROM stocks WHERE userId = {$_SESSION["uid"]} AND symbol = {$symbol}");

  mysqli_query($connection, "UPDATE users SET cash = cash + $value WHERE uid = {$_SESSION["uid"]}");

?>

<div style="text-align: center">
  Venda efetuada com sucesso no valor de R$<?= $shares["shares"] ?>!
</div>