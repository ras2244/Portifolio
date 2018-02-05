 $(document).ready(function(){

    //translate to FR
    if(window.location.pathname.includes(("/fr/")) ){
        $("#name_LANG").html("Nom");
        $("#email_LANG").html("Adresse courriel");
        $("#subscribe_LANG").html("ABONNEZ-VOUS À NOTRE INFOLETTRE");
        $("#copy_LANG").html("Copyright 2017 Alexa Translations. Tous droits réservés.");
        $("#connect_lang").html("SUIVEZ-NOUS:");
    }

    //translate to EN
    if(window.location.pathname.includes(("/en/")) ){
        $("#name_LANG").html("Name");
        $("#email_LANG").html("Email");
        $("#subscribe_LANG").html("SUBSCRIBE TO OUR NEWSLETTER:");
        $("#copy_LANG").html("Copyright 2017 Alexa Translations. All rights reserved.");
        $("#connect_lang").html("CONNECT WITH US:");

    //nav dropdown functionality 
    function nav_drop(){
        // alert("Working")
        $("#alexa_main_nav").show();

        //current menu
        var cur_menu = $("#alexa-nav").find(".current_page_item");
        var cur_menu_html = $("#alexa-nav").find(".current_page_item > a").html();


        //add '-REQUEST A QUOTE-' line to the last array
        var quoteHtml = "";

        //check current language and print out 
        if(window.location.pathname.includes(("/fr/")) ){
            quoteHtml = "<p class='cst-req-a-Q req-fr'> - Demander un devis -</p>";
        }

        if(window.location.pathname.includes(("/en/")) ){
            quoteHtml = "<p class='cst-req-a-Q'> - REQUEST A QUOTE -</p>";
        }

        $("#alexa-nav:last-child a:last").append(quoteHtml);


        // the <ul> tag containing the hidden dropdown
        var alexa_nav_drop = $("#alexa-nav").find("ul");
        
        //the <li> tag and its bootstrap attribute
        $(alexa_nav_drop).parent().addClass("dropdown");
        // attr("class", "dropdown ");

        //the <a> tag and add its attribute
        $(alexa_nav_drop).prev().attr("class", "dropdown-toggle");
        $(alexa_nav_drop).prev().attr("data-toggle", "dropdown");
        $(alexa_nav_drop).prev().attr("role", "button");
        $(alexa_nav_drop).prev().attr("aria-haspopup", "true");
        $(alexa_nav_drop).prev().attr("aria-expanded", "false");
        $(alexa_nav_drop).prev().append(" <i class='fa fa-caret-down' aria-hidden='true'></i>");

        // the <ul> tag under <li> tag
        $(alexa_nav_drop).attr("class", "dropdown-menu cst-sub-menu");


        // Sub menu of dropdown menu
        var subDrop = $("#alexa-nav > li > ul > li.dropdown");
        subDrop.children("a").removeAttr("class");
        subDrop.children("a").removeAttr("data-toggle");
        subDrop.children("a").removeAttr("role");
        subDrop.children("a").removeAttr("aria-expanded");
        subDrop.children("a").removeAttr("aria-haspopup");
        subDrop.children("a").children("i").attr("class", "fa fa-caret-right");

        // subDrop.attr("id", "sector_sub");

        //activate sub dropdown when its is hovered
        subDrop.on("mouseenter", function() {
          subDrop.children("ul").addClass("rightMenu");
          subDrop.children("ul").show(); 
        }).on('mouseleave', function() {
          subDrop.children("ul").hide();  
        });

        // activate dropdown when <a> is clicked
        $(alexa_nav_drop).prev().click(function(e){
          $(this).parent().addClass("open");
        });


        //show current page in menu 
        var cur_menu_parent = cur_menu.parent();


        if(cur_menu_parent.hasClass('dropdown-menu')  ){
            //check sub menu
            if(cur_menu_parent.parent().parent().hasClass('dropdown-menu')){
                console.log(cur_menu.parent().prev().html().replace(/<[^>]*>/g, "") );
                var parent_subMenu_txt = cur_menu.parent().prev().html().replace(/<[^>]*>/g, "");
                cur_menu_parent.parent().parent().prev().append("<span class='menu-span-pg'>"+parent_subMenu_txt+" > "+cur_menu_html+"</span>");
                console.log(cur_menu_parent.parent().parent().prev());
                cur_menu_parent.parent().parent().prev().addClass("cst-teal");
                // console.log("parent of parent has dropdown");
                // cur_menu.hide();
            }else{
                cur_menu.parent().prev().append("<span class='menu-span-pg'>"+cur_menu_html+"</span>");
                cur_menu.parent().prev().addClass("cst-teal");
            }
            
        }else{
            cur_menu.find("a").addClass("cst-teal");
        }



    }

    // Function to check URL and toggle EN - FR link display on header
    function toggleLangUrl(){

        /**
        * This function is to read the url
        *   param and display the language links accordingly.
        */

        var url = window.location.pathname;
        var en = $("#en-link");
        var fr = $("#fr-link");

        if(url.includes("/en/")){
            en.addClass("cst-hidden");
            fr.removeClass("cst-hidden");
            return;
        }

        if(url.includes("/fr/")){
            fr.addClass("cst-hidden");
            en.removeClass("cst-hidden");
            return;
        }

        // Supress warning if no 'fr' or 'en' found in the url
        if(!en.hasClass("cst-hidden")){
            $("#en-link").addClass("cst-hidden");
        }
        if(!fr.hasClass("cst-hidden")){
            $("#fr-link").addClass("cst-hidden");
        }
        // warning message
        // alert("Please install polylang to activate 'EN' & 'FN' links. If you have polylang install, please make sure to untick the 'Hide URL language' option in the polylang -> language -> settings -> URL Modifications.");
    }

    //toggle language links
    function toggle_links(){

        /**
        * This function is to postion the links on mobile view
        * and to add custom class to french menu 
        */
        var url = window.location.pathname; 
        var eng_link = $("#en-link");
        var fr_link = $("#fr-link");
        var _div = $("#langDiv");
        // var _div = $("#navbar-header");
        var logo = $(".cst-brand-logo");
        var srchBtn = $("#search-btn-toggle");
        

        //check link whether french version 
        if(url.includes("/fr/")){
             //check media size (upto 1400)
            if (window.matchMedia("(max-width: 1400px)").matches){

                _div.append(eng_link,fr_link);

                if(!eng_link.hasClass("cst-mobile-links") || !fr_link.hasClass("cst-mobile-links") ){
                    eng_link.addClass("cst-mobile-links");
                    fr_link.addClass("cst-mobile-links");   
                } 

                // Add custom class to fix language position links with a div
                if(!_div.hasClass("lang_div")){
                    _div.addClass("lang_div");
                }

                //remove padding from logo
                if(logo.hasClass("cst-no-padding")){
                    logo.removeClass("cst-no-padding");
                }

                //add custom class
                if(!srchBtn.hasClass("mobile-btn-fr")){
                    srchBtn.addClass("mobile-btn-fr");
                }

            }else{
                if(!logo.hasClass("cst-no-padding")){
                    logo.addClass("cst-no-padding");
                }
            }

        }else{
             //check media size (upto 1214)
            if (window.matchMedia("(max-width: 1214px)").matches){

                 _div.append(eng_link,fr_link);
                if(!eng_link.hasClass("cst-mobile-links") || !fr_link.hasClass("cst-mobile-links") ){
                    eng_link.addClass("cst-mobile-links");
                    fr_link.addClass("cst-mobile-links");   
                } 

                // Add custom class to fix language position links with a div
                if(!_div.hasClass("lang_div")){
                    _div.addClass("lang_div");
                }

                if(logo.hasClass("cst-no-padding")){
                    logo.removeClass("cst-no-padding");
                }
                if(!srchBtn.hasClass("mobile-btn-fr")){
                    srchBtn.addClass("mobile-btn-fr");
                }
            }else{
                if(!logo.hasClass("cst-no-padding")){
                    logo.addClass("cst-no-padding");
                }
            }
        }

        //listener for resizing media
        window.addEventListener('resize', function () {

            //add custom classes to menu when on french
            //check link whether french version 
            if(url.includes("/fr/")){

                //check media size (upto 1400)
                if (window.matchMedia("(max-width: 1400px)").matches){
                    if(logo.hasClass("cst-no-padding")){
                        logo.removeClass("cst-no-padding");
                    }
                    if(!srchBtn.hasClass("mobile-btn-fr")){
                        srchBtn.addClass("mobile-btn-fr");
                    }
                }else{
                    if(!logo.hasClass("cst-no-padding")){
                        logo.addClass("cst-no-padding");
                    }
                }

                //move element once hit mobile size
                if (window.matchMedia("(max-width: 1400px)").matches){

                    _div.append(eng_link,fr_link);

                    //add custom mobile class
                    if(!eng_link.hasClass("cst-mobile-links") || !fr_link.hasClass("cst-mobile-links") ){
                        eng_link.addClass("cst-mobile-links");
                        fr_link.addClass("cst-mobile-links");   
                    } 

                    //add class to div language 
                    if(!_div.hasClass("lang_div")){
                        _div.addClass("lang_div");
                    }

                }
                else{
                    //reset position once out of mobile view
                    $("#search-from-container > div >form > div").append(eng_link,fr_link);
                    //remove custom mobile class
                    if(eng_link.hasClass("cst-mobile-links") || fr_link.hasClass("cst-mobile-links") ){
                        eng_link.removeClass("cst-mobile-links");
                        fr_link.removeClass("cst-mobile-links");   
                    } 

                    // remove language div class
                    if(_div.hasClass("lang_div")){
                        _div.removeClass("lang_div");
                    }
                }
                return;
            }

            //--------------Default for english --------------------//

            //check media size (upto 1214)
            if (window.matchMedia("(max-width: 1214px)").matches){
                if(logo.hasClass("cst-no-padding")){
                    logo.removeClass("cst-no-padding");
                }
                if(!srchBtn.hasClass("mobile-btn-fr")){
                    srchBtn.addClass("mobile-btn-fr");
                }
            }else{
                if(!logo.hasClass("cst-no-padding")){
                    logo.addClass("cst-no-padding");
                }
            }

            //move element once hit mobile size
            if (window.matchMedia("(max-width: 1214px)").matches){

                _div.append(eng_link,fr_link);

                //add custom mobile class
                if(!eng_link.hasClass("cst-mobile-links") || !fr_link.hasClass("cst-mobile-links") ){
                    eng_link.addClass("cst-mobile-links");
                    fr_link.addClass("cst-mobile-links");   
                } 

                //add class to div language 
                if(!_div.hasClass("lang_div")){
                    _div.addClass("lang_div");
                }

            }
            else{
                //reset position once out of mobile view
                $("#search-from-container > div >form > div").append(eng_link,fr_link);
                //remove custom mobile class
                if(eng_link.hasClass("cst-mobile-links") || fr_link.hasClass("cst-mobile-links") ){
                    eng_link.removeClass("cst-mobile-links");
                    fr_link.removeClass("cst-mobile-links");   
                } 

                // remove language div class
                if(_div.hasClass("lang_div")){
                    _div.removeClass("lang_div");
                }
            }


        });
    }


    //run functions
    nav_drop();
    toggleLangUrl();
    toggle_links();

    
});


/**
*   Form submit for Newsletter Subscription and its validation 
*/
$("#signUpForm").submit(function(e){

    e.preventDefault();

    var server_uri = $("#defaultDirectoryUri").val();   

    var form = $("#signUpForm");
    var form_ser = form.serialize();
    var formData = new FormData(form);

    console.log(form);
    console.log(form_ser);
    console.log(formData);
    console.log(server_uri);

    var sucInfo = $("#sub_form_success");
    var errInfo = $("#sub_form_error");

    $.ajax({
        url: server_uri+'/inc/newsletterSignup.php',
        method: "POST",
        data: form_ser,
        success: function(data){
            console.log(data);
            if(isJson(data)){
                data = JSON.parse(data);
                console.log(data);
                if(data.status == 200){

                    //hide error message if displaying
                    if(errInfo.css("display") == "block" ){
                        errInfo.css("display", "none");
                    }

                    //display server message
                    $("#sub_form_success > div").html("<strong>Success! </strong>"+data.msg);
                    //animate display
                    sucInfo.show("fast");

                    //reset values
                    form.find("input[type='text'], input[type='email']").val(" ");
                    return;
                }

                //hide success message if displaying
                if(sucInfo.css("display") == "block" ){
                    sucInfo.css("display", "none");
                }

                //display error message
                $("#sub_form_error > div").html("<strong>Error! </strong>"+data.msg);
                //animate display
                errInfo.show("fast");


            }else{
                JSON.parse(data);
                console.log(data);
            }
            // window.location.reload();
        },
        error: function(data){
            alert("Something went wrong! Reloading page");
            window.location.reload();
        }
    });

});

// small function to check whether a string can be JSON-ified
function isJson(str) {
    try {
        JSON.parse(str);
    } catch (e) {
        return false;
    }
    return true;
}

//Hides the parent element 
function hideElement(e, elem){

    e.preventDefault();

    var elem = $(elem);
    var parentDiv = elem.parent();

    if(parentDiv.css("display") == "none"){
        //return if already hidden
        return;
    }

    //hide parentDiv
    parentDiv.hide();
    return;
}