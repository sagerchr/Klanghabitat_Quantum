
struct valueType {
  float value;
  char name[20];
  int assignedPot;
  int selcted;
  int ID;
  GUI_COLOR Color;
};

struct Encoder {
  float value;
  int assignedControl;
  int buttonState;
  int doubleclickEvent;
  GUI_COLOR Color;
};


struct valueType attack;
struct valueType makeUpGain;
struct valueType release;
struct valueType ratio;

struct valueType input;
struct valueType distortion;
struct valueType gain;
struct valueType threshold;
struct valueType outputgain;


int Enc_AttackSelected;
int Enc_ReleaseSelected;
int Enc_InputSelected;
int Enc_DistortionSelected;
int Enc_MakeUpGainSelected;
int Enc_OutputSelected;
int Enc_RatioSelected;

int nothingSelected;


struct Encoder Encoder1;
struct Encoder Encoder2;
struct Encoder Encoder3;
struct Encoder Encoder4;
