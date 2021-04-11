<?

    // require common code
    require_once("includes/common.php");

?>

<!DOCTYPE html>

<html>

  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>CC50 Finanças: Quote</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <div id="middle">
      <form action="quote2.php" method="post">
        <table>
          <tr>
            <td>Quote:</td>
            <td><input name="symbol" type="text" placeholder="Ex: AAPL"></td>
          </tr>
        </table>
      </form>
    </div>
  </body>

</html>