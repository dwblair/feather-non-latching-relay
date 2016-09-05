// Demo Code for SerialCommand Library
// Craig Versek, Jan 2014
// based on code from Steven Cogswell, May 2011

#include <SerialCommand.h>

#define arduinoRELAY 6   // Relay "Signal" pin on shiel needs to be connected to this pin on Feather.

SerialCommand sCmd(Serial);         // The demo SerialCommand object, initialize with any Stream object

void setup() {
  pinMode(arduinoRELAY, OUTPUT);      // Configure the onboard RELAY for output
  digitalWrite(arduinoRELAY, HIGH);    // default to RELAY on

  Serial.begin(9600);

  // Setup callbacks for SerialCommand commands
  sCmd.addCommand("ON",    RELAY_on);          // Turns RELAY on
  sCmd.addCommand("OFF",   RELAY_off);         // Turns RELAY off  
  sCmd.addCommand("HELLO", sayHello);        // Echos the string argument back
  sCmd.addCommand("SLEEP",     processCommand);  // Converts two arguments to integers and echos them back
  sCmd.setDefaultHandler(unrecognized);      // Handler for command that isn't matched  (says "What?")
  //Serial.println("Ready");
}

void loop() {
  int num_bytes = sCmd.readSerial();      // fill the buffer
  if (num_bytes > 0){
    sCmd.processCommand();  // process the command
  }
  delay(10);
}


void RELAY_on(SerialCommand this_sCmd) {
  this_sCmd.println("RELAY on");
  digitalWrite(arduinoRELAY, HIGH);
}

void RELAY_off(SerialCommand this_sCmd) {
  this_sCmd.println("RELAY off");
  digitalWrite(arduinoRELAY, LOW);
}

void sayHello(SerialCommand this_sCmd) {
  char *arg;
  arg = this_sCmd.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL) {    // As long as it existed, take it
    this_sCmd.print("Hello ");
    this_sCmd.println(arg);
  }
  else {
    this_sCmd.println("Hello, whoever you are");
  }
}


void processCommand(SerialCommand this_sCmd) {
  int sleepSeconds;
  int waitSeconds;
  char *arg;
  int argCount=0;

  //this_sCmd.println("Sleep Command:");
  arg = this_sCmd.next();
  if (arg != NULL) {
    argCount++;
    waitSeconds = atoi(arg);    // Converts a char string to an integer
    //this_sCmd.print("First argument was: ");
    //this_sCmd.println(sleepSeconds);
  }
  else {
    //this_sCmd.println("No arguments");
  }

  arg = this_sCmd.next();
  if (arg != NULL) {
    argCount++;
    sleepSeconds = atol(arg);
    //this_sCmd.print("Second argument was: ");
    //this_sCmd.println(waitSeconds);
  }
  else {
    //this_sCmd.println("No second argument");
  }

  if (argCount==2) {
  this_sCmd.print("Going to sleep for ");
  this_sCmd.print(sleepSeconds);
  this_sCmd.print(" seconds.  Will first wait ");
  this_sCmd.print(waitSeconds);
  this_sCmd.println(" for Beagle Bond shutdown process.");

  //wait 
  this_sCmd.print("Waiting ");
  this_sCmd.print(waitSeconds);
  this_sCmd.println(" seconds ...");
  delay(waitSeconds*1000); // delay takes milliseconds as argument

  //sleep
  this_sCmd.print("Sleeping ");
  this_sCmd.print(sleepSeconds);
  this_sCmd.print(" seconds ...");
  digitalWrite(arduinoRELAY, LOW);
  delay(sleepSeconds*1000);

  //wake up
  this_sCmd.println("Waking up ...");
  digitalWrite(arduinoRELAY, HIGH);

  }
  else {
  this_sCmd.println("SLEEP command requires two integer arguments: \"SLEEP sleepSeconds waitSeconds\""); 
  }
}

// This gets set as the default handler, and gets called when no other command matches.
void unrecognized(SerialCommand this_sCmd) {
  SerialCommand::CommandInfo command = this_sCmd.getCurrentCommand();
  this_sCmd.print("Did not recognize \"");
  this_sCmd.print(command.name);
  this_sCmd.println("\" as a command.");
}
