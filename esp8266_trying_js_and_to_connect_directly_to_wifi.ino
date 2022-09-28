#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#ifndef STASSID
#define STASSID "ali"
#define STAPSK  "alihassan"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

String html = "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n    <meta charset=\"UTF-8\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <style>\n\n\n    /* Design */\n    *,\n    *::before,\n    *::after {\n      box-sizing: border-box;\n    }\n\n    html {\n    \n      padding: 0;\n      margin: 0;\n      color:white;\n    }\n\n    body {\n      font-weight: 400;\n      letter-spacing: 0;\n      padding: 0;\n      margin: 0;\n\n      \n  background-color: #010e30;\n    }\n\n    .main{\n      max-width: 1200px;\n      margin: 0 auto;\n    }\n\n    h1 {\n        font-size: 24px;\n        font-weight: 400;\n        text-align: center;\n    }\n\n\n    .btn {\n      color: white;\n      padding: 0.8rem;\n      font-size: 14px;\n      text-transform: uppercase;\n      border-radius: 4px;\n      font-weight: 400;\n      display: block;\n      width: 100%;\n      cursor: pointer;\n      border: 3px solid rgba(0, 0, 0, 0.2);\n      background: #faad14;\n      box-shadow: 0 10px 10px -14px rgba(0, 0, 0, 0.25);\n    }\n\n    .btn:hover {\n      background-color: #ff5a00;\n    }\n\n    .cards {\n      display: flex;\n      flex-wrap: wrap;\n      list-style: none;\n      margin: 0;\n      padding: 0;\n      \n      \n    \n    }\n\n    .cards_item {\n      display: flex;\n      padding: 1rem;\n      margin: auto;\n      height: 600px;\n      \n      width:85%;\n      \n    }\n    \n  \n  .card {\n    box-shadow: 0 20px 40px -14px rgba(0, 0, 0, 0.25);\n    display: flex;\n    flex-direction: column;\n    overflow: hidden;\n    background-color: #161557;\n    width:100%;\n    border-radius: 3px;\n  }\n  .card img {\n      padding-bottom: 10px;\n      height:300px;\n\n      object-fit: cover;\n  }\n  \n  .card_content {\n      padding: 0 10px;\n  }\n  \n  .card_title {\n    color: #fff;\n    font-size: 1.1rem;\n    font-weight: 700;\n    letter-spacing: 1px;\n    text-transform: capitalize;\n    margin: 0px;\n  }\n  \n  .card_text {\n    color: white;\n    font-size: 0.875rem;\n    line-height: 1.5;\n    margin-bottom: 1.25rem;    \n    font-weight: 400;\n  }\n \n  \n  #checklist {\n       background: var(--background);\n       position: relative;\n       box-shadow: 0 10px 30px rgba(65, 72, 86, 0.05);\n       padding: 30px 15px;\n       color: #fff;\n\n  }\n  \n  \n  * {\n  padding: 0;\n  margin: 0;\n  box-sizing: border-box;\n}\n\nhtml {\n  font-size: 14px;\n}\n@media (min-width: 768px) {\n  html {\n    font-size: 16px;\n  }\n}\n\nbody {\n  font-family: \"Poppins\", sans-serif;\n  color: #777;\n}\n\n.wrapper {\n  padding: 3rem 1rem;\n}\n@media (min-width: 768px) {\n  .wrapper {\n    padding-top: 25vh;\n  }\n}\n\n.jumbotron {\n  width: 540px;\n  max-width: 100%;\n  padding: 3rem;\n  margin: 0 auto;\n  border-radius: 0.8rem;\n  text-align: center;\n}\n.jumbotron h2 {\n  margin: 0.6em 0 2em;\n  font-weight: 400;\n  letter-spacing: 0.0452em;\n}\n\nfooter {\n  position: absolute;\n  left: 0;\n  right: 0;\n  bottom: 10vh;\n  padding: 1rem;\n}\nfooter ol {\n  display: flex;\n  justify-content: center;\n  flex-direction: column;\n  align-items: center;\n}\nfooter ol li {\n  list-style: none;\n}\nfooter ol li a {\n  display: inline-block;\n  font-size: 0.8rem;\n  padding: 0.4em 1em;\n  color: #777;\n  font-weight: 300;\n  letter-spacing: 0.0452em;\n  transition: all 0.3s ease;\n}\nfooter ol li a:hover {\n  opacity: 0.45;\n}\n@media (min-width: 768px) {\n  footer ol {\n    flex-direction: row;\n  }\n  footer ol li + li {\n    border-left: 1px solid #ddd;\n  }\n}\n\n.drop {\n  display: inline-block;\n  position: relative;\n  text-align: center;\n}\n.drop input[type=checkbox] {\n  display: none;\n}\n.drop input[type=checkbox]:checked ~ .drop-items {\n  opacity: 1;\n  max-height: 400px;\n  padding: 0.6rem 0;\n}\n.drop input[type=checkbox]:checked ~ .control {\n  z-index: 99;\n  box-shadow: 0 0 0 2px #5055b1;\n}\n.drop input[type=checkbox]:checked ~ .control:after {\n  transform: rotate(180deg);\n}\n.drop input[type=checkbox]:checked ~ .overlay-close {\n  transform: none;\n  pointer-events: initial;\n}\n.drop .control {\n  position: relative;\n  color: #fff;\n  display: inline-block;\n  cursor: pointer;\n  padding: 0.8em 1.2em;\n  background: #30336b;\n  border-radius: 4px;\n  transition: all 0.3s ease;\n}\n@media (hover: hover) {\n  .drop .control:hover {\n    opacity: 0.75;\n  }\n}\n.drop .control:after {\n  content: \"\";\n  display: inline-block;\n  height: 0.5em;\n  width: 0.5em;\n  margin-left: 0.8em;\n  background-image: url(\"data:image/svg+xml,%3Csvg fill='%23fff' xmlns='http://www.w3.org/2000/svg' width='16' height='13.838' viewBox='0 0 16 13.838'%3E%3Cpath d='M15.78,12.753a1.529,1.529,0,0,1-1.311,2.314H1.53A1.529,1.529,0,0,1,.219,12.753L6.69,1.969a1.528,1.528,0,0,1,2.619,0L15.78,12.753Z' transform='translate(16 15.067) rotate(180)'/%3E%3C/svg%3E%0A\");\n  background-repeat: no-repeat;\n  background-position: center;\n  background-size: contain;\n  transition: transform 0.3s ease;\n}\n.drop .drop-items {\n  position: absolute;\n  top: calc(100% + .4rem);\n  width: 100%;\n  padding: 0;\n  margin: 0;\n  transition: all 0.3s ease;\n  background: #fff;\n  box-shadow: 0 2px 6px rgba(0, 0, 0, 0.15);\n  border-radius: 4px;\n  overflow: hidden;\n  max-height: 0;\n  opacity: 0;\n  z-index: 99;\n}\n.drop .drop-items .item-drop {\n  list-style: none;\n}\n.drop .drop-items .item-drop a {\n  display: block;\n  color: #555;\n  text-decoration: none;\n  padding: 0.6rem;\n  transition: all 0.3s ease;\n}\n@media (hover: hover) {\n  .drop .drop-items .item-drop a:hover {\n    background: #eee;\n  }\n}\n.drop .overlay-close {\n  position: fixed;\n  top: 0;\n  left: 0;\n  bottom: 0;\n  right: 0;\n  z-index: 9;\n  transform: translate(100%, 0);\n  pointer-events: none;\n}\n\nselect{\n  padding: 5px;\n  background-color: #1C6673;\n  border: none;\n  border-radius: 3px;\n  color:white;\n  margin-right:6px;\n}\noption{\n  background-color:#144A52;\n}\n\n@media (min-width: 40rem) {\n        .cards_item {\n          \n          width: 50%;\n        }\n      }\n      \n      @media (min-width: 56rem) {\n        .cards_item {\n          width: 33.3333%;\n        }\n      }\n    \n    </style>\n    <title>RoboChief</title>\n</head>\n<body>\n  <div class=\"main\">\n    <h1>Order A Tasty and Smart Meal</h1>\n    <ul class=\"cards\">\n      \n      \n      <li class=\"cards_item\">\n        <div class=\"card\">\n            <img src=\"https://pinchofyum.com/wp-content/uploads/Instant-Pot-Mac-and-Cheese-Square.jpg\">\n          <div class=\"card_content\">\n            <h2 class=\"card_title\">Mac N Cheese</h2>\n            <p class=\"card_text\">Deliciously rich and gooey, this baked mac and cheese is creamy, comforting, and PERFECT for the holidays, as well as a comforting family dinner!</p>\n            \n            <div id =\"checklist\">\n              <!-- Dropdown -->\n              <select id=\"MNC-Chedder\">\n                <option value=\"0\" selected>Regular Chedder</option>\n                <option value=\"1\">Extra Chedder</option>\n              </select>\n              \n        \n              <!-- END -- Dropdown -->\n              <!-- Dropdown -->\n              <select id=\"MNC-spices\">\n                <option value=\"00\" selected>Without spices</option>\n                <option value=\"01\">Few Spices</option>\n                <option value=\"10\">Regular Spices</option>\n                <option value=\"11\">Extra Spices</option>\n              </select>\n                  <!-- END -- Dropdown -->\n                </label>  \n              \n            </div>\n            \n            \n            \n            <button id = \"Macncheese\" class=\"btn card_btn\" onclick=\"handleMacncheese()\">Order</button>\n          </div>\n        </div>\n      </li>\n\n\n      <li class=\"cards_item\">\n        <div class=\"card\">\n          <img src=\"https://www.dontgobaconmyheart.co.uk/wp-content/uploads/2019/11/spicy-chicken-pasta-1.jpg\">\n          <div class=\"card_content\">\n            <h2 class=\"card_title\">Chicken Pasta</h2>\n            <p class=\"card_text\">A wise man once said \"There is always a room for more pasta\".</p>\n\n            <div id =\"checklist\">\n              <select id=\"CP-chicken\">\n                <option value=\"0\" selected>Regular Chicken</option>\n                <option value=\"1\">Extra Chicken</option>\n              </select>\n              <select id=\"CP-spices\">\n                <option value=\"00\" selected>Without spices</option>\n                <option value=\"01\">Few Spices</option>\n                <option value=\"10\">Regular Spices</option>\n                <option value=\"11\">Extra Spices</option>\n              </select>\n              \n            </div>\n\n            <button id = \"Chickenpasta\" class=\"btn card_btn\" onclick=\"handleChickenpasta()\">Order</button>\n          </div>\n        </div>\n      </li>\n      <li class=\"cards_item\">\n        <div class=\"card\">\n            <img src=\"https://desiturka.ca/wp-content/uploads/2022/01/CHICKEN-TIKKA-MASALA-14.jpg\">\n          <div class=\"card_content\">\n            <h2 class=\"card_title\">Chicken Masala</h2>\n            <p class=\"card_text\">Made with love</p>\n            \n            <div id =\"checklist\">\n              <input id=\"CM-onions\" type=\"checkbox\" checked>\n              <label for=\"CM-onions\">Onions</label>\n              <select id=\"CM-spices\">\n                <option value=\"00\" selected>Without spices</option>\n                <option value=\"01\">Few Spices</option>\n                <option value=\"10\">Regular Spices</option>\n                <option value=\"11\">Extra Spices</option>\n              </select>\n            </div>\n\n            <button id = \"chicken_masala\" class=\"btn card_btn\" onclick=\"handleChickenmasala()\">Order</button>\n          </div>\n        </div>\n      </li>\n      <li class=\"cards_item\">\n        <div class=\"card\">\n            <img src=\"https://www.errenskitchen.com/wp-content/uploads/2018/11/ROAST-POTATOES-2.jpg\">\n          <div class=\"card_content\">\n            <h2 class=\"card_title\">Crispy Potato</h2>\n            <p class=\"card_text\">Lorem Lopsum sadasdasds dasd sads sdasdsad sad</p>\n\n            <div id =\"checklist\">\n              <input id=\"CrPt-Salt\" type=\"checkbox\" checked>\n              <label for=\"CrPt-Salt\">Salt</label>\n              <input id=\"CrPt-spices\" type=\"checkbox\">\n              <label for=\"CrPt-spices\">Spices</label>\n            </div>\n\n            <button id = \"potato\" class=\"btn card_btn\" onclick=\"handleCrispyPotato()\">Order</button>\n          </div>\n        </div>\n      </li>\n      <li class=\"cards_item\">\n        <div class=\"card\">\n          <img src=\"https://static.toiimg.com/thumb/54659021.cms?imgsize=275086&width=800&height=800\">\n          <div class=\"card_content\">\n            <h2 class=\"card_title\">Fried Fries</h2>\n            <p class=\"card_text\">Keep your friends close and your fries closer.</p>\n\n            <div id =\"checklist\">\n              <input id=\"FF-Salt\" type=\"checkbox\" checked>\n              <label for=\"FF-Salt\">Salt</label>\n              <input id=\"FF-spices\" type=\"checkbox\">\n              <label for=\"FF-spices\">Spices</label>\n            </div>\n\n            <button id = \"potato2\" class=\"btn card_btn\" onclick=\"handlePotato()\">Order</button>\n          </div>\n        </div>\n      </li>\n      <li class=\"cards_item\">\n        <div class=\"card\">\n          <img src=\"https://lifemadesimplebakes.com/wp-content/uploads/2020/05/rice-pudding-resize-6-500x375.jpg\">\n          <div class=\"card_content\">\n            <h2 class=\"card_title\">Rice Pudding</h2>\n            <p class=\"card_text\"></p>\n\n            \n\n            <button id=\"roz_bleban\" class=\"btn card_btn\" onclick=\"handleRozbleban()\">Order</button>\n          </div>\n        </div>\n      </li>\n      \n    </ul>\n  </div>\n  \n  <script>\n    \n\n    function handleMacncheese(){\n      \n      let mncChedder = document.getElementById('MNC-Chedder').value;\n      let mncSpices = document.getElementById('MNC-spices').value;\n      \n      let x = \"001\" + \"00\" + mncChedder + mncSpices;\n      console.log(x);\n      window.location = x;\n    } \n \n    function handleRozbleban(){\n      let x = \"01100000\";\n      \n      window.location=x;\n      console.log(x);\n    }\n \n    function handleChickenpasta(){\n      let cpChicken = document.getElementById('CP-chicken').value;\n      let cpSpices = document.getElementById('CP-spices').value;\n\n      let x = \"010\" + \"00\" + cpChicken + cpSpices;\n      \n      window.location=x;\n      console.log(x);\n    }\n    function handleChickenmasala(){\n\n      let cmOnions = document.getElementById('CM-onions').checked ? 1 :0;\n      let cmSpices = document.getElementById('CM-spices').value;\n\n      let x = \"100\" + \"00\" + cmOnions + cmSpices;\n      \n      window.location=x;\n      console.log(x);\n    }\n \n    function handlePotato(){\n      let x = \"10100000\";\n      \n      window.location=x;\n      //console.log(carrot.checked);\n    }\n\n    function handleCrispyPotato(){\n      let x = \"11000000\";\n      \n      window.location=x;\n      //console.log(carrot.checked);\n    }\n\n\n\n </script>\n      \n</body>\n</html>";

// TCP server at port 80 will respond to HTTP requests
WiFiServer server(80);

bool checkreq(String s){
  for(int i; i<s.length(); i++){
    if(s[i]!=0 || s[i]!=1){
      return false;
    }
  }
  return true;
  }


unsigned char ASCIItoBinary(String &str){
  return ((str[0]-48)<<7)|((str[1]-48)<<6)|((str[2]-48)<<5)|((str[3]-48)<<4)|((str[4]-48)<<3)|((str[5]-48)<<2)|((str[6]-48)<<1)|((str[7]-48));}
void setup(void) {
  Serial.begin(9600);


  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  
  WiFi.begin(ssid, password);


  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

 

  // Start TCP (HTTP) server
  server.begin();
  //Serial.println("TCP server started");


}

void loop(void) {


  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait for data from client to become available
  while (client.connected() && !client.available()) {
    delay(1);
  }

  // Read the first line of HTTP request
  String req = client.readStringUntil('\r');

  // First line of HTTP request looks like "GET /path HTTP/1.1"
  // Retrieve the "/path" part by finding the spaces
   //Serial.println(req);
  int addr_start = req.indexOf(' ');

  int addr_end = req.indexOf( ' ',addr_start+1 );
  if (addr_start == -1 || addr_end == -1) {
    //Serial.print("Invalid request: ");
    
    return;
  }
  req = req.substring(addr_start + 2, addr_end);
 

  if(req.length()==8){
    for(int i; i<req.length(); i++){
      if(req[i]!=0 || req[i]!=1){
        return;
      }
    }
    Serial.write(ASCIItoBinary(req));
    client.flush();
  }
  client.print(html);
  
  
}
