<?php


function displayForm() {

	echo	"<div id='form-container'>
					<h2>PLEASE FILL OUT FORM</h2>

					<form method='post'>  
   
   						<table>
        
   							<tr>
   								<td><label for='name'>Name</label></td>
   							</tr>
   							<tr>
   								<td><input id='name' name='name' placeholder='Your name' required></td>
   							</tr>
   							
   							<tr>
   								<td><label for='email'>Email</label></td>
   							</tr>
   							<tr>
   								<td><input id='email' name='email' type='email' placeholder='Your email address' required></td>
   							</tr>
   							<tr>
            
   			 					<td><label for='dob'>Date of Birth</label></td>
   			 					
   			 				<tr><td>";
   			 				
    								displayDateOfBirthMonth();
    								displayDateOfBirthDay();
    								displayDateOfBirthYear();
       
    						echo 	"</td></tr>
    						
    							<tr>
    						
    								<td><input id='submit' type='submit' value='Submit'></td>
    								
    							</tr>
    
    						</table>
    
					</form>

				</div>";
}



function displayDateOfBirthMonth() {


	echo 	"<select name='month' id='month'>
			<option>Month</option>
			<option value='1'>January</option>
			<option value='2'>Febuary</option>
			<option value='3'>March</option>
			<option value='4'>April</option>
			<option value='5'>May</option>
			<option value='6'>June</option>
			<option value='7'>July</option>
			<option value='8'>August</option>
			<option value='9'>September</option>
			<option value='10'>October</option>
			<option value='11'>November</option>
			<option value='12'>December</option>
		</select>";
	

} // end function




function displayDateOfBirthDay() {


	echo 	"<select name='day' id='day'>
			<option>Day</option>";
			
			
			for ($i = 1; $i <= 31; $i++) {
    			
    				echo "<option value='$i'>$i</option>";
			}
			

		echo "</select>";
	

} // end function




function displayDateOfBirthYear() {

	$year = date("Y");


	echo 	"<select name='year' id='year'>
			<option>Year</option>";
			
			
			for ($i = $year; $i >= 1900; $i--) {
    			
    				echo "<option value='$i'>$i</option>";
			}
			
	
		echo "</select>";
	

} // end function


?>