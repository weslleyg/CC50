<?

    require_once("includes/common.php");

    $amount = mysqli_real_escape_string($connection, $_POST["amount"]);

    if(!is_numeric($amount))
      apologize("Valor inválido!");

    mysqli_query($connection, "UPDATE users SET cash = cash + $amount WHERE uid = {$_SESSION["uid"]}");
?>

<div style="text-align: center">
 Depositado com sucesso!
</div>
