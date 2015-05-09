<?php

class AjaxList {

	// Constructor
    	function AjaxList() {}
    
    

    	// Add data to Database
    	function getData() {
  	
        	$name 	= $_POST["name"];
		$email 	= $_POST["email"];
        	$month 	= $_POST['month'];
        	$day 	= $_POST['day'];
        	$year 	= $_POST['year'];
        	$dob 	= "$month/$day/$year";
        	
            
        	$string = "INSERT INTO `ajax_data` SET `name`='{$name}',`email`='{$email}', `dob`='{$dob}', `when`=UNIX_TIMESTAMP()";
        	$result = queryDataBase($string);
        	
        	

   	} // end function
 


    	function displayData($bOnlyMessages = false) {


        	$string = "SELECT `ajax_data`.*, UNIX_TIMESTAMP()-`ajax_data`.`when` AS 'diff' 
        	FROM ajax_data ORDER BY `id` DESC LIMIT 5";
        	
        	$result = queryDataBase($string);
        	

        	$output = '';
        
        
        	// display list of data
        	while ($myrow = mysql_fetch_array($result, MYSQL_ASSOC)) {
        	
        		$id 	= $myrow['id'];
        		$name 	= $myrow['name'];
        		$email	= $myrow['email'];
        		$dob	= $myrow['dob'];


            		$styles = $js = '';
            		$diff = $myrow['diff'];
    
            		
            		if ($diff < 7) {
                		$styles = "style='display:none;'";
                		$js = "<script> $('#message_$id').slideToggle('slow'); </script>";
           	 	}
            		
            		
            		$output .= "<div class='message' id='message_$id' $styles><b>Name:</b> $name <br> <b>Email:</b> $email <br> <b>DOB:</b> $dob</div>" . $js;
            
        	} // end while
        
        
        	if ($bOnlyMessages) 
        		return $output;
        	
        	return '<h2>OUTPUT</h2><div class="output_list">' . $output . '</div>';
        	
        	
    	} // end function
    
    
} // end class


	$GLOBALS['AjaxList'] = new AjaxList();

?>