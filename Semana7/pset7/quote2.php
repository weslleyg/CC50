<?

    require_once("includes/common.php");

    $quote = mysqli_real_escape_string($connection, $_POST["symbol"]);

    $s = lookup($quote);

    if($s === NULL)
        apologize("Ticket de ação inválido!");

?>

<div style="text-align: center">
 A ação <?= $s->name ?> atualmente custa $<?= $s->price ?>.
</div>
