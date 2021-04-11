<?

    require_once("includes/common.php");

    $s = lookup($_POST["symbol"]);

    echo("<script type='text/javascript'> console.log($s);</script>");

    print($s->price);

?>