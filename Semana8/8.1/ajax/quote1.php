<?

    /**
     * quote1.php
     *
     * Devolve pre�o de uma a��o como texto/html.
     *
     * CC50
     * Gabriel Guimar�es
     */

    // faz a pesquisa
    $handle = @fopen("http://download.finance.yahoo.com/d/quotes.csv?s={$_GET["symbol"]}&f=e1l1", "r");
    if ($handle !== FALSE)
    {
        $data = fgetcsv($handle);
        if ($data !== FALSE && $data[0] == "N/A")
            print($data[1]);
        fclose($handle);
    }
?>
