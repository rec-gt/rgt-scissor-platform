class DisplayOLED {
private:
  enum MsgEnum {
    INIT,
    PRINT_ERR,
    PRINT_MSG,
    PRINT_WARNING,
  };

  MsgEnum lastState;
  MsgEnum currState;

  void clear() {
  }

  void plotMsg(byte lh, String msg) {
    Serial.println(msg);
  }

  void send() {
  }
public:
  bool init() {
    this->lastState = INIT;
    return true;
  }

  DisplayOLED& render(void (*callback)(), MsgEnum currState) {
    if (this->lastState != currState) {
      this->lastState = currState;
      return *this;
    }
  }

  void print1(MsgEnum currState) {
    if (this->lastState != currState) {
      this->clear();
      this->plotMsg(0, "系統運作中！");
      this->send();

      this->lastState = currState;
    }
  }

  void print2() {
    this->clear();
    this->plotMsg(0, "系統暫停運作！");
    this->send();
  }

  void print3() {
    this->clear();
    this->plotMsg(0, "感應器" + str);
    this->plotMsg(1, "偵測到障礙物");
    this->plotMsg(2, "系統暫停運作！");
    this->send();
  }
};