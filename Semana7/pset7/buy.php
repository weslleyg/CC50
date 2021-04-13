<!DOCTYPE html>

<html>

  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>CC50 Finanças: Buy</title>
  </head>

  <body>

    <div id="top">
      <a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
    </div>

    <div id="middle">
      <form action="buy2.php" method="post">
        <table>
          <tr>
            <td>Ticket:</td>
            <td><input name="symbol" type="text" placeholder="Ex: AAPL"></td>
          </tr>
          <tr>
            <td>Amount:</td>
            <td><input name="shares" type="text" placeholder="Ex: 100"></td>
          </tr>
          <tr>
            <td></td>
            <td><input type="submit" value="Comprar"></td>
          </tr>
        </table>
      </form>
    </div>
  </body>

</html>