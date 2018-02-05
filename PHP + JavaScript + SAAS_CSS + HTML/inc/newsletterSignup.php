<?php
	
	//connect to Alexa Database
	include "connect.php";

	// Import PHPMailer v-6 classes into the global namespace
	// use PHPMailer\PHPMailer\PHPMailer;
	// use PHPMailer\PHPMailer\Exception;

	// require '../PHPMailer/src/Exception.php';
	// require '../PHPMailer/src/PHPMailer.php';
	// require '../PHPMailer/src/SMTP.php';

	//ver 5.2.16
	require "../PHPMailer/PHPMailerAutoload.php";

	if($_SERVER['REQUEST_METHOD'] == 'POST'){

		//variables 
		$name; $email; $data = '';//data that is sent back (if any)
		$sql_insert_newsletter = "INSERT INTO newsletter_subscribers (user_name, user_email) VALUES (:user_name, :user_email)";

		if(isset($_POST['signupName']) && !empty($_POST['signupName']) ){

			//set name variable if set
			$name = $_POST['signupName'];
			
			//validate name format using regular expression
			if(validate_reg($name, "text") == false){
				//return json encode 
				die('{"status": "401", "msg": "Sorry, the name should only contain text.", "data": "'.$data.'" }');
			}

		}else{
			//return json encode 
			die('{"status": "401", "msg": "Please enter name!", "'.$data.'" }');

		}

		if(isset($_POST['signupEmail']) && !empty($_POST['signupName']) ){
			//set email variable if set
			$email = $_POST['signupEmail'];

			//validate email format using regular expression
			if(validate_reg($email, "email") == false){
				//return json encode 
				die('{"status": "401", "msg": "Sorry, this email is not in the right format", "data": "'.$data.'" }');
			}

			//check if email exist
			if(email_exist($email)){
				//return json encode 
				die('{"status": "401", "msg": "Sorry, this email is already registered.", "data": "'.$data.'" }');
			}

		}else{
			//return json encode 
			die('{"status": "401", "msg": "Please enter Email!", "data": "'.$data.'" }');
		}


		$mail_sub = new PHPMailer(true); //instantiate mail class for subscriber
		$mail_own = new PHPMailer(true); //instantiate mail class for owner

		try {

			/** PDO Transaction start */
			$conn->beginTransaction();

		    //Server settings
		    $mail_sub->isSMTP();                                      // Set mailer to use SMTP
		    $mail_own->isSMTP();

	        $mail_sub->Host = "localhost";
	        $mail_own->Host = "localhost";
		    // $mail->Host = 'smtp1.example.com;smtp2.example.com';  // Specify main and backup SMTP servers

		    $mail_sub->SMTPAuth = false;                               // Enable SMTP authentication
		    $mail_sub->Port = 25;                                    // TCP port to connect to

		    $mail_own->SMTPAuth = false;
		    $mail_own->Port = 25;

		    $mail_sub->Priority = 1;

		    //To Subscriber
		    $mail_sub->setFrom('no-reply@alexatranslations.com', 'Alexa Translation Subscription');  
		    $mail_sub->addAddress($email, $name); // Add a recipient
		    // $mail->addCC('cc@example.com');
		    // $mail->addBCC('bcc@example.com');

		    //To Owner
		    $mail_own->setFrom('no-reply@alexatranslations.com', 'Subscriber to Alexa Translation');
		    //$mail_own->addAddress('saeed.77711@gmail.com', 'Subscriber');     // Add a recipient

		    //Content to subscriber 
		    $mail_sub->isHTML(true);                                  // Set email format to HTML
		    $mail_sub->Subject = 'Alexa Translations Newsletter Subscription';
		    $mail_sub->Body    = 'Thank you for your subscription. ';
		    $mail_sub->AltBody = 'Thank You for your subscription.';

		    //Content to Owner
		    $mail_own->isHTML(true);                                  // Set email format to HTML
		    $mail_own->Subject = 'Alexa Translations Newsletter Subscription';
		    $mail_own->Body    = $name.' has just signed up! Email:- '.$email;
		    $mail_own->AltBody = $name.' has just signed up! Email:- '.$email;

		    /** insert into database */
		    $exe_insert_newsletter = $conn->prepare($sql_insert_newsletter);
		    $exe_insert_newsletter -> bindParam(':user_name', $name, PDO::PARAM_STR); //insert as string
		    $exe_insert_newsletter -> bindParam(':user_email', $email, PDO::PARAM_STR); //insert as string
		    $exe_insert_newsletter -> execute();

		    /** Send emails*/
		    // $mail_sub->send(); //send to subscriber
		    // $mail_own->send(); //send to owner

		    /** PDO Transaction commit */
			$conn->commit();



		    //return json encode 
			echo '{"status": "200", "msg": "Registration Complete!", "data": "'.$data.'" }';

		} catch (Exception $e) {
			/** Roll back the transaction if something goes wrong */
			$conn->rollback(); 

		    // echo 'Message could not be sent.';
		    // echo 'Mailer Error: ' . $mail_sub->ErrorInfo;
		    // echo 'Mailer Error: ' . $mail_own->ErrorInfo;
		    // echo $e->getMessage();
		    die( '{"status": "500", "msg": "Server Error! Fail to subscribe!", "data":" '.$e->getMessage().'. Owner Mailer Error: '.$mail_own->ErrorInfo.'. Subscriber Mailer Error: '.$mail_sub->ErrorInfo.' "}');

		}

	}

	//validator for input using regular expression
	function validate_reg($input, $type){
		$reg_text = "/^[a-zA-Z ]*$/i"; 
		// ^[a-zA-Z ]*$
		// /^[a-z]+$/i
		
		/** Regular expression for email source:- http://regexlib.com/REDetails.aspx?regexp_id=192 */
		$reg_email = "/^[\w-]+(?:\.[\w-]+)*@(?:[\w-]+\.)+[a-zA-Z]{2,7}$/i"; 

		if($type == "text"){
			if (preg_match($reg_text, $input) == 1) {

			    // echo "A match was found for ".$input;
			    return true;

			} else {

			    // echo "A match was not found for ".$input;
			    return false;
			}
		}

		if($type == "email"){
			if (preg_match($reg_email, $input) == 1) {

			    // echo "A match was found for ".$input;
			    return true;
			} else {

			    // echo "A match was not found for ".$input;
			    return false;
			}
		}

	}

	function email_exist($input){
		$sql = "SELECT * FROM newsletter_subscribers WHERE user_email = '$input' ";

		$exe_sql = $GLOBALS['conn']->prepare($sql);
		$exe_sql->execute();

		//fetch the data returned if any (returns ARRAY)
		$get_sql = $exe_sql -> fetchAll(PDO::FETCH_ASSOC);

		//check row count of SQL 
		if($exe_sql->rowCount() == 0){
			//return false for 'no email exist'
			return false;
		}

		//attach the data found on database
		$GLOBAlS['data'] = json_encode($get_sql);

		//return true for 'email exist'
		return true;
	}
?>