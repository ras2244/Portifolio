<?php 
/**
*	Connection to database with username and password
*
*/
	/**     FOR ACTUAL DEPLOYMENT        */
	$severname = "utilities.db.3914537.f0d.hostedresource.net"; //MySQL server host
	$username = "utilities"; //MySQL username
	$passwd = 	"zhX9C3UhxfDV@"; //MySQL password
	$dbname = "utilities"; //database name


	/**     FOR LOCALHOST TESTING        */
	// $severname = "localhost"; //MySQL server host
	// $username = "root"; //MySQL username
	// $passwd = 	""; //MySQL password
	// $dbname = "alexa-database"; //database name

	try {

		// connection to database
		$conn = new PDO("mysql:host=$severname;dbname=$dbname", $username, $passwd);

	}catch (PDOException $e){
		// echo $e->getMessage();
		die('{"status": "500", "msg": "Error connecting to DB.", "data": '.json_encode($e->getMessage()).'  }');
	}

?>