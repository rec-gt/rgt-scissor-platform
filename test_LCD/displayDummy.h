class DisplayOLED {
private:
  enum MsgStatus {
    INIT,
    PRINT_ERR,
    PRINT_MSG,
    PRINT_WARNING,
  };

  MsgStatus lastState;
  MsgStatus currState;

  void clear() {
  }

  void send() {
  }

  void plotMsg(String msg, MsgStatus currState) {
    if (this->lastState != currState) {
      this->clear();
      Serial.println(msg);
      this->send();

      this->lastState = currState;
    }
  }
public:
  bool init() {
    this->lastState = INIT;
    return true;
  }

  void print1() {
    this->plotMsg("ERR001", PRINT_ERR);
  }

  void print2() {
    this->plotMsg("MSG001", PRINT_MSG);
  }

  void print3() {
    this->plotMsg("WARN001", PRINT_WARNING);
  }
};