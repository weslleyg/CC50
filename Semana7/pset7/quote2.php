<?

    require_once("includes/common.php");

    $s = lookup($_POST["symbol"]);

    if($s === NULL)
        apologize("Ticket de ação inválido!");

?>

<div style="text-align: center">
 A ação <?= $s->name ?> atualmente custa $<?= $s->price ?>.
</div>
