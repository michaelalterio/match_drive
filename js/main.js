$(function() {


	getMessages = function() {
	
        	var self = this;
        	var _sRandom = Math.random();  

        	$.getJSON('index.php?action=get_last_messages' + '&_r=' + _sRandom, function(data){
        	
        	
            		if(data.messages) {
                		$('.output_list').html(data.messages);
            		}


            		// start it again;
            		setTimeout(function(){
               			getMessages();
            		}, 5000);
            		
        	}); // end getJSON
        	
    	} // end function
    	
    	
    getMessages();
    
    
});