<html>
 <head><title>HTML Form Example</title></head>
 <body>
 <?php
if($_post){
		$firstname = $_post['firstname']
		$lastname = $_post['lastname']
}
if(empty($firstname)||empty($lastname)){
		echo ' please insert your first and last name';
}
?>

    <form method="POST" action="displayforminfo.php">
      First Name: <input type="text" name="firstname" value="<?php echo $firstname ?>"> <br>
      Last name: <input type="text" name="lastname" value="<?php echo $lastname ?>"> <br>
      <input type="submit" value="GO">
    </form>
 </body>
 </html>