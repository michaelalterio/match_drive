$(document).ready(function() {


	// JS Spinner Options
	var opts = {
		lines: 13, // The number of lines to draw
		length: 11, // The length of each line
		width: 5, // The line thickness
		radius: 17, // The radius of the inner circle
		corners: 1, // Corner roundness (0..1)
		rotate: 0, // The rotation offset
		color: '#FFF', // #rgb or #rrggbb
		speed: 1, // Rounds per second
		trail: 60, // Afterglow percentage
		shadow: false, // Whether to render a shadow
		hwaccel: false, // Whether to use hardware acceleration
		className: 'spinner', // The CSS class to assign to the spinner
		zIndex: 2e9, // The z-index (defaults to 2000000000)
		top: 'auto', // Top position relative to parent in px
		left: 'auto' // Left position relative to parent in px
	};





	$("body").on("click", "form #submit", function(e){
	
		e.preventDefault(); // Prevent default Submit functions
	});


	$("body").on("click", "form #submit", function(e){

		var formData = $('form').serialize(); // get form data

		var name = $.trim($("#name").val());
		var email = $.trim($("#email").val());
		
		var month = $("#month").val();
		var day = $("#day").val();
		var year = $("#year").val();
		
		
		var age = 18;
		var mydate = new Date();
		mydate.setFullYear(year, month-1, day);

		var currdate = new Date();
		currdate.setFullYear(currdate.getFullYear() - age);
		
		var emailReg = /^([\w-]+(?:\.[\w-]+)*)@((?:[\w-]+\.)*\w[\w-]{0,66})\.([a-z]{2,6}(?:\.[a-z]{2})?)$/i;
		
		var nameError = false; var emailError = false; var dobError = false;
		
				
			
		if(name == null || name == '') {
		
			nameError = true;
			
			if ( $(".nameError").length == 0)
				$("label[for='name']").append("<i class='fa nameError'>&#xf06a;<span>Please enter your name.</span></i>");
			
		} // end if
		
		else
			$(".nameError").remove();	
			
		
		
		
		if (!emailReg.test(email)) {
		
			emailError = true;
			
			if ( $(".emailError").length == 0)
				$("label[for='email']").append("<i class='fa emailError'>&#xf06a;<span>Please enter a valid email address.</span></i>");	
				
		} // end if
		else
			$(".emailError").remove();
			
			
			
			
		if (((currdate - mydate) < 0) || (mydate == 'Invalid Date')) {
		
			dobError = true;
			
			if ( $(".dobError").length == 0)
				$("label[for='dob']").append("<i class='fa dobError'>&#xf06a;<span>Please enter a valid DOB (18 and over).</span></i>");
	
		} // end if
		else
			$(".dobError").remove();


		
		if(nameError || emailError || dobError) {
		
			if ( $(".error-message").length == 0) {
				$("<div class='error-message' style='display:none'>Form submission failed. Please correct the errors below and try again.</div>").insertBefore("form").slideDown("fast");
				
				
			}
				
			$("body").animate({scrollTop:0}, 'slow');
			
		} // end if
		
		else {
			$(".error-message").remove();
			$('.ui-ios-overlay').remove();


			var target = document.createElement('div');
			document.body.appendChild(target);
			var spinner = new Spinner(opts).spin(target);
			iosOverlay({
				text: 'Updating List',
				duration: 2e3,
				spinner: spinner
			});
			
			
			$(this).off(e); // allows only one submission
			
			
			// Sends form to processForm.php
			$.ajax({
				type: 'POST',
				url: 'processForm.php',
				data: formData,
				success: function(data) {

					$("#form-container h2").replaceWith('<h2>THANK YOU FOR YOUR SUBMISSION</h2>');
			
					$("form").slideUp("normal");
					
					$("body").animate({scrollTop:0}, 'slow');
					
					
					$("#form-container").append("<img class='icons' src='images/icon_1.png'><img class='icons' src='images/icon_2.png'><img class='icons' src='images/icon_3.png'><img class='icons' src='images/icon_4.png'><img class='icons' src='images/icon_5.png'><img class='icons' src='images/icon_6.png'>");
						
 					
				} // end success

			}); // end ajax
			
					
		} // end else
		
		
		return false;
		
		
	}); // end submit.click function
	
	
	
	
}); // end document.ready function