<?

    // require common code
    require_once("includes/common.php");

?>

<!DOCTYPE html>

<html>

  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>CC50 Finanças: Depositar</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <div id="middle">
      <form action="deposit2.php" method="post">
        <table>
          <tr>
            <td>Quantidade:</td>
            <td><input name="amount" type="text" placeholder="Ex: 1130.44"></td>
          </tr>
          <tr>
            <td></td>
            <td><input type="submit" value="Depositar"></td>
          </tr>
        </table>
      </form>
    </div>
  </body>

</html>