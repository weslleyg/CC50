<?

    // require common code
    require_once("includes/common.php");

?>

<!DOCTYPE html>

<html>

  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>CC50 Finanças: trades</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <? $result = mysqli_query($connection, "SELECT type, symbol, shares, price, date FROM trades WHERE userId = {$_SESSION["uid"]}"); ?>
    <? while ($row = mysqli_fetch_array($result)): ?>
      <? $s = lookup($row["symbol"]); ?>
      <tr>
        <td><?= $s->name ?></td>
        <td><?= $row["symbol"] ?></td>
        <td><?= $row["type"] ?></td>
        <td><?= $row["shares"] ?></td>
        <td><?= $row["price"] ?></td>
        <td><?= $row["date"] ?></td>
      </tr><br>
    <? endwhile ?>

  </body>

</html>
