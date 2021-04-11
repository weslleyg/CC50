<?

    // require common code
    require_once("includes/common.php"); 

    // escape username and password for safety
    $username = mysqli_real_escape_string($connection, $_POST["username"]);
    $password = mysqli_real_escape_string($connection, $_POST["password"]);
    $password2 = mysqli_real_escape_string($connection, $_POST["password2"]);

    if(strcmp($password, $password2))
      apologize("As senhas não correspondem!");
    
    if(empty($username) || empty($password) || empty($password2))
      apologize("Espaços não preenchidos");

    // prepare SQL
    $sql = "INSERT INTO users (username, password, cash) VALUES('$username', '$password', 10000.00)";

    // execute query
    $result = mysqli_query($connection, $sql);

    if($result == false)
      apologize("O usuário já existe!");

    $uid = mysqli_insert_id($connection);

    // if we found a row, remember user and redirect to portfolio
    if ($uid != 0)
    {
        // cache uid in session
        $_SESSION["uid"] = $uid;

        // redirect to portfolio
        redirect("index.php");
    }

    // else report error
    else
        apologize("Usuário e/ou senha inválidos!");

?>
