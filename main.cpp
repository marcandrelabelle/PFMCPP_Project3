/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()





struct EchoMachine
{
    EchoMachine();
    int numPlaybackHead;
    float headSpacing;
    float tapeSaturation;  
    float springReverbMix;
    float outputLvl;
    float tapeReadSpeed;

    struct Overdrive 
    {
        Overdrive();
        float clippingPoint;
        float lowPassFreq;
        int inputSigIndex;
        float sigMix;
        float outputLvl;

        void limitSig (int inputSig, int limiTresh,bool autoMakeUpGain);
        void filterSig (int inputIndex, float q,float freq, char filterType);
        void distortionType (char distoType);
    };

    void distorSignal ();

    void repeatSoundSource (bool repeatState, float loopStart,float loopEnd, float looplength);

    void tapeSpeed (bool playTape, int tapeSpeed);
};

EchoMachine::EchoMachine()
{
    numPlaybackHead = 0;
    headSpacing = 0.0f;
    tapeSaturation = 0.0f;  
    springReverbMix = 0.0f;
    outputLvl = 0.0f;
    tapeReadSpeed = 0;
}

EchoMachine::Overdrive::Overdrive()
{
    clippingPoint = 0.0f;
    lowPassFreq = 0.0f;
    inputSigIndex = 0;
    sigMix = 0.0f;
    outputLvl = 0.0f;
}


void EchoMachine::Overdrive::limitSig(int inputSig, int limiTresh, bool autoMakeUpGain)
{
    if (autoMakeUpGain == 1)
    {
        sigMix += inputSig * limiTresh;
    }
    else
    {
        sigMix += inputSig;
    }
    
}

void EchoMachine::Overdrive::filterSig(int inputIndex, float q, float freq, char filterType = 'a')
{
    float centerQ = 0;

    centerQ = q * freq;
    inputSigIndex = inputIndex;
    lowPassFreq+= freq;
    
    if (filterType == 'a')
    {
        centerQ += 0.5f;
    }
    else
    {
        centerQ += 1.f;
    }

     std::cout << "EchoMachine::Overdrive::filterSig " << centerQ  << std::endl;
    
}

void EchoMachine::Overdrive::distortionType(char distoType)
{
    if (distoType == 'F')
    {
        clippingPoint = 0.01f;
        lowPassFreq = 1200;
    }
    else
    {
        clippingPoint = 0.6f;
        lowPassFreq = 8000;
    }

    std::cout << "EchoMachine::Overdrive::distortionType " << distoType  << std::endl;
}

void EchoMachine::distorSignal ()
{
    std::cout << "EchoMachine::distorSignal " << numPlaybackHead << std::endl;  //2) printing out something interesting
}

void EchoMachine::repeatSoundSource (bool repeatState, float loopStart, float loopEnd, float looplength)
{
    if (repeatState && (looplength > 30))
    {
        outputLvl = 1.0f;
        headSpacing = loopEnd - loopStart;
    }
    else
    {
        outputLvl = 0.0f;
    }
}

void EchoMachine::tapeSpeed (bool playTape, int tapeSpeed)
{
    if (playTape)
    {
        tapeReadSpeed *= tapeSpeed;
    }
    else
    {
        tapeReadSpeed = 1;
    }
}

struct SolideStateAmp
{
    SolideStateAmp();
    int numSpeakers;
    float speakerSize;
    float masterLvl;
    int ampModelingPresets;
    float fxvl;

    void signalProcessing (bool processSignal, int sampleStart, int sampleEnd);
    void imitateTubeAmp (int ampSelectIndex, std::string speakerIr); 
    void amplifieSound (int inputSig, float gain);
};

SolideStateAmp::SolideStateAmp()
{
    numSpeakers = 0;
    speakerSize = 0.0;
    masterLvl = 0.0;
    ampModelingPresets = 0;
    fxvl = 0.0 ;
}

void SolideStateAmp::signalProcessing(bool processSignal, int sampleStart, int sampleEnd)
{
   sampleEnd = (processSignal != 1) ? 0 : 1 + sampleStart;
}

void SolideStateAmp::imitateTubeAmp(int ampSelectIndex, std::string speakerIr)
{
    if (ampSelectIndex <= 50 && speakerIr == "Celestion")
    {
        numSpeakers = 4;
        speakerSize = 12.0f;
    }
    else
    {
        numSpeakers = 2;
        speakerSize = 10.0f; 
    }
}

void SolideStateAmp::amplifieSound(int inputSig, float gain)
{
    masterLvl = (inputSig * gain)/100;
}

struct SamplingPad
{
    SamplingPad();
    int numPads;
    int numIntergratedInst; 
    bool stereoOut; 
    int samplingSpaceSec;
    int numIntegratedFx;
    int padSteps;

    void trigSnd ();
    void playSequence (int numSteps, int bpm, bool startSequence);
    int sendMidi (int midiNoteNum, int midiVel, bool noteEvent, bool isCc);
};

SamplingPad::SamplingPad()
{
    numPads = 0;
    numIntergratedInst = 0; 
    stereoOut = true; 
    samplingSpaceSec = 0;
    numIntegratedFx = 0;
    padSteps = 0;

}

void SamplingPad::trigSnd(){}

void SamplingPad::playSequence(int numSteps, int bpm, bool startSequence)
{
    padSteps = (startSequence == 1) ? numSteps * bpm : 0;
    std::cout << "SamplingPad::playSequence " << padSteps << std::endl;
}

int SamplingPad::sendMidi(int midiNoteNum, int midiVel, bool noteEvent, bool isCc)
{
    return (noteEvent && isCc == 0) ? midiNoteNum : midiVel;
}

struct AnalogConsole
{
    AnalogConsole();
    int numChannelStrips;
    int numAudioSend; 
    int numMonitorOut;
    int numStereoChanels;
    int selectedCh;
    float panner;
    float outputGain;
    bool preFader;

    void mixSounds (int trackNum, float trackLvl, float pan); 
    void masterOut (float masterOutdB);
    float addTone (float hiFreq, float hiBoost, float midFreq, float midBoost, float bassFreq, float bassBoost);
};

AnalogConsole::AnalogConsole()
{
    numChannelStrips = 0;
    numAudioSend = 0; 
    numMonitorOut = 0;
    numStereoChanels = 0;
    selectedCh = 0;
    panner = 0.0f;
    outputGain = 0.0f;
    preFader = false;
}


void AnalogConsole::mixSounds(int trackNum, float trackLvl,float pan)
{
    selectedCh = trackNum + 1;
    outputGain = trackLvl * -6.0f;
    panner = pan - 1;
}

void AnalogConsole::masterOut(float masterOutdB)
{
    if (masterOutdB < -6.0f && masterOutdB > -12.0f )
    {
        outputGain = -6.0f * 1;
    }
}

float AnalogConsole::addTone(float hiFreq, float hiBoost, float midFreq, float midBoost, float bassFreq, float bassBoost)
{
    float tone;
   
    if (hiBoost > 0.5f)
    {
        tone = (hiFreq * hiBoost) + (midFreq * midBoost) + (bassFreq * bassBoost) ;
    }
    else
    {
        tone = 800.0f + hiBoost;
    }
    
    return tone;
}

struct DawMixer
{
    DawMixer();
    int maxNumFaders;
    float panPos; 
    float recBtnDiameter;
    float sliderLenght;
    float lvl;
    int numInserts;


    void recordReady ();
    void panSnd (float pan);
    void audioVolume (float laudioLvl, float normalize);
};

DawMixer::DawMixer()
{
    maxNumFaders = 0;
    panPos = 0.0f; 
    recBtnDiameter = 0.0f;
    sliderLenght = 0.0f;
    lvl = 0.0f;
    numInserts = 0;
}

void DawMixer::recordReady(){}

void DawMixer::panSnd(float pan)
{
    panPos += pan;
}

void DawMixer::audioVolume (float laudioLvl, float normalize)
{
    lvl = laudioLvl * normalize;
}

struct VirtualMidiKey
{
    VirtualMidiKey();
    int numOctaves; 
    int numMidiChanels;
    int keyboardSize; 
    bool invertKeyColour;
    int velocityRange;

    void sendMidi (int keyIndex, int velocity);
    int displayMidi (char noteName);
    void receiveInputKey (int inputNum, int midiChanel);
};

VirtualMidiKey::VirtualMidiKey()
{
    numOctaves = 0; 
    numMidiChanels = 0;
    keyboardSize = 0; 
    invertKeyColour = false;
    velocityRange = 0;
}

void VirtualMidiKey::sendMidi(int keyIndex, int velocity)
{
    keyboardSize = keyIndex * numOctaves;
    velocityRange += velocity;
}

int VirtualMidiKey::displayMidi(char noteName)
{
    return noteName;
}

void VirtualMidiKey::receiveInputKey(int inputNum, int midiChanel)
{
    numMidiChanels -= (inputNum + midiChanel);
}

struct ToolbarDocker
{
    ToolbarDocker();
    int numDockerTools;
    float toolSelectorSize;
    float dockerPosX;
    float dockerWidth;
    int numDockerRow;

    void changeTool (int toolListIndex, int replaceIndex);
    int customizeTool (int indexSwitch, int newToolIndex);
    bool activateMetronom (bool metroPlay);
};

ToolbarDocker::ToolbarDocker()
{
    numDockerTools = 0;
    toolSelectorSize = 0.0f;
    dockerPosX = 0.0f;
    dockerWidth = 0.0f;
    numDockerRow = 0; 
}

void ToolbarDocker::changeTool(int toolListIndex, int replaceIndex)
{
    numDockerTools = toolListIndex + replaceIndex;   
}

int ToolbarDocker::customizeTool(int indexSwitch, int newToolIndex)
{
    return indexSwitch - newToolIndex;
}

bool ToolbarDocker::activateMetronom(bool metroPlay)
{
   bool state;

   if (metroPlay)
   {
       state = true;
   }
   else
   {
       state = false;
   }
   
    return state;
}

struct PerformanceMeter
{
    PerformanceMeter();
    float textSize;
    float windowSize;
    std::string fontStyle;
    std::string backGroundColor;
    double cpuClockSpeed;

    void displayCpu (int posX, int posY, float width, float height,bool active, double cpuClock);
    void displayRam (int posX, int posY, float width, float height,bool active);
    void displayDiskRead (int posX, int posY, float width, float height,bool active);
};

PerformanceMeter::PerformanceMeter()
{
    textSize = 0;
    windowSize = 0.0f;
    fontStyle = "arial";
    backGroundColor = "green";
    cpuClockSpeed = 0.0; 
}

void PerformanceMeter::displayCpu(int posX, int posY, float width, float height, bool active, double cpuClock)
{
    int numLines = 8;
    textSize = height/numLines;

    if(active)
    {
        windowSize = (width * height) - (posX + posY);
        cpuClockSpeed = cpuClock * 2;
    }
    else
    {
        windowSize = 0;
    }
}

void PerformanceMeter::displayRam(int posX, int posY, float width, float height, bool active)
{
    if (active)
    {
        textSize = height/100;
        windowSize = (width * height) - (posX + posY);
        fontStyle = "default";
    }
    else
    {
        fontStyle = "arial";
    }

}

void PerformanceMeter::displayDiskRead(int posX, int posY, float width, float height, bool active)
{
    if (active)
    {
        textSize = height/25;
        windowSize = (width*height) - (posX +posY);
        fontStyle = "default";
    }
    else
    {
        fontStyle = "arial";
    }
}

struct TempoEnv
{
    TempoEnv();
    int bpm;
    bool linearPointShape;
    int numPoints;
    std::string tempoSignature;
    std::string envLineColour;

    void changeBpm (int newBpm);
    float newPoint (float newPointPosX, float newPointPosY, bool pointShape); 
    void deletePoint (int pointIndex);
};

TempoEnv::TempoEnv()
{
    bpm = 128;
    linearPointShape = true;
    numPoints = 200;
    tempoSignature = "7/8";
    envLineColour = "purple"; 
}

void TempoEnv::changeBpm(int newBpm)
{
    bpm = newBpm;
}

float TempoEnv::newPoint(float newPointPosX, float newPointPosY,bool pointShape)
{
    float floor = 0.01f;
    float newDot;

    if (numPoints < 200 && pointShape == true)
    {
        newDot = (newPointPosX * newPointPosY) + floor;
    }
    else
    {
        newDot = (newPointPosX * newPointPosY) + (floor * 2);
    }

    return newDot; 
}

void TempoEnv::deletePoint(int pointIndex)
{
    int newIndex;
    newIndex = pointIndex * 1;
}

struct DigitalWorkstation
{
    DigitalWorkstation();
    DawMixer mixer;
    VirtualMidiKey midiKeys;
    ToolbarDocker toolDocker;
    PerformanceMeter perfoMeter;
    TempoEnv tempoEnveloppe;
    bool recStatus = false;

    struct TransportBar
    {
        TransportBar();
        bool transportBarShow;
        bool playBtnActive;
        bool showPlayRate;
        float sartTimeSelectionPoint;
        float endTimeSelectionPoint;

        void loopSelection(bool loopSelection);
        float tapTempoBpm (int numTap, float time);
        int moveCursorPos (int beat, int mesure);
    };

    float loopAudioSection (float loopIn, float loopOut);
    void recordData (int input, bool isMidi);
    float bounce (int tracks, float startingPoint, float endingPoint);
};

DigitalWorkstation::DigitalWorkstation()
{
    
}

DigitalWorkstation::TransportBar::TransportBar()
{
    transportBarShow = true;
    playBtnActive = false;
    showPlayRate = true;
    sartTimeSelectionPoint = 0.0f;
    endTimeSelectionPoint = 24.0f;
}


float DigitalWorkstation::loopAudioSection(float loopIn, float loopOut)
{
    return loopIn - loopOut;
}

void DigitalWorkstation::recordData(int input, bool isMidi)
{
   recStatus = (isMidi && input > -1);
}

float DigitalWorkstation::bounce(int tracks, float startingPoint, float endingPoint)
{
    int bouncedTrack = tracks + 1;
    float trackLength = startingPoint - endingPoint ;
    
    return bouncedTrack -  trackLength;
}

void DigitalWorkstation::TransportBar::loopSelection(bool loopSelection)
{
    if (loopSelection)
    {
        loopSelection = false;
    }
}

float DigitalWorkstation::TransportBar::tapTempoBpm(int numTap, float time)
{
    return  numTap/time;
}

int DigitalWorkstation::TransportBar::moveCursorPos(int beat, int mesure)
{
    return beat * mesure;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Example::main();
    EchoMachine echoMch;
    EchoMachine::Overdrive overDr;
    SamplingPad sampPad;

    echoMch.distorSignal();
    overDr.filterSig (0, 1.0,500.50f, 'a');
    sampPad.playSequence(8, 120, true);

    std::cout << "EchoMachine echoMch " << (echoMch.outputLvl <= 0.0f ? "not loud enough" : "louder!!!!") << "\n";

    std::cout << "EchoMachine::Overdrive overDr = " << (overDr.clippingPoint <= 0.0f ? " need more Clipping...pleasee!!!" : "YASSSSS") << "\n";

    std::cout << "good to go!" << std::endl;
}
