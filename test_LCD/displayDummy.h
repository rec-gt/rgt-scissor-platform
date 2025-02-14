class DisplayOLED {
private:
  enum StateEnum {
    INIT,
    PRINT_ERR,
    PRINT_MSG,
    PRINT_WARNING,
  };

  StateEnum lastState;

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

  void print(StateEnum currState, String addStr = "") {
    if (this->lastState == currState) {
      return;
    }
    this->lastState = currState;

    // handle all plotting cases here
    this->clear();

    switch (currState) {
      case INIT:
        this->plotMsg(1, "正在加載保護系統...");
        break;
      case PRINT_ERR:
        this->plotMsg(0, "感應器" + addStr);
        this->plotMsg(1, "偵測到障礙物");
        this->plotMsg(2, "系統暫停運作！");
        break;
      case PRINT_MSG:
        this->plotMsg(0, "系統允許暫時");
        this->plotMsg(1, "運作十秒！");
        break;
      case PRINT_WARNING:
        this->plotMsg(0, "系統暫停運作！");
        break;
      default:
        break;
    }

    this->send();
  }
};