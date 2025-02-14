enum StateEnum {
  INIT,
  PRINT_ERR,
  PRINT_MSG,
  PRINT_WARNING,
};

class DisplayOLED {
private:
  StateEnum lastState;

  void clear() {
  }

  void plot(byte lh, String msg) {
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
        this->plot(1, "正在加載保護系統...");
        break;
      case PRINT_ERR:
        this->plot(0, "感應器" + addStr);
        this->plot(1, "偵測到障礙物");
        this->plot(2, "系統暫停運作！");
        break;
      case PRINT_MSG:
        this->plot(0, "系統允許暫時");
        this->plot(1, "運作十秒！");
        break;
      case PRINT_WARNING:
        this->plot(0, "系統暫停運作！");
        break;
      default:
        break;
    }

    this->send();
  }
};