 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Foot
    {
        void stepForward();
        int stepSize(int size);
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::Foot::stepForward(){}

int Person::Foot::stepSize(int size)
{
    return size;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        distanceTraveled += leftFoot.stepSize(howFast) + rightFoot.stepSize(howFast);
    }
    else
    {
        distanceTraveled += rightFoot.stepSize(howFast) + leftFoot.stepSize(howFast);
    }
}
/*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you decide to write empty functions, you will need to fill them in with code in part 3.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 */

struct EchoMachine
{
    int numPlaybackHead = 4;
    float headSpacing = 1.2f;
    float tapeSaturation = 9.9f;  
    float springReverbMix = 5.0f;
    float outputLvl = 0.85f;

    struct Overdrive 
    {
        float clippingPoint = 0.8f;
        float lowPassFreq = 800.0f;
        int inputSigIndex = 1;
        float sigMix = 0.5f;
        float outputLvl = 0.7f;

        void limitSig (int inputSig, int limiTresh,bool autoMakeUpGain);
        void filterSig (int inputIndex, float q,float freq, char filterType);
        void distortionType (char distoType);
    };

    void distorSignal ();

    void repeatSoundSource (bool repeatState, float loopStart,float loopEnd, float looplength);

    void tapeSpeed (bool playTape, int tapeSpeed);
};

void EchoMachine::Overdrive::limitSig(int inputSig, int limiTresh, bool autoMakeUpGain)
{
    sigMix += inputSig * (limiTresh + autoMakeUpGain);
}

void EchoMachine::Overdrive::filterSig(int inputIndex, float q, float freq, char filterType = 'a')
{
    inputSigIndex = inputIndex;
    q += 0.0f;
    freq = lowPassFreq+=0;
    
    if (filterType == 'a')
    {
        q += 0.5f;
    }
    else
    {
        q += 1.f;
    }
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
}

void EchoMachine::distorSignal (){}

void EchoMachine::repeatSoundSource (bool repeatState, float loopStart, float loopEnd, float looplength)
{
    if (repeatState)
    {
        outputLvl = 1.0f;
        loopStart = 0.0f;
        loopEnd = looplength;
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
        tapeSpeed = 1;
    }
    else
    {
        tapeSpeed = 0;
    }
}

struct SolideStateAmp
{
    int numSpeakers = 2;
    float speakerSize = 12.0f;
    float masterLvl = 6.3f;
    int ampModelingPresets = 99;
    float fxvl = 4.3f;

    void signalProcessing (bool processSignal, int sampleStart, int sampleEnd);
    void imitateTubeAmp (int ampSelectIndex, std::string speakerIr); 
    void amplifieSound (int inputSig, float gain);
};

void SolideStateAmp::signalProcessing(bool processSignal, int sampleStart, int sampleEnd)
{
    if (processSignal != 1)
    {
        sampleStart = 0;
        sampleEnd = 0;
    }
    else
    {
        sampleStart = 0;
        sampleEnd = 1;
    }
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
    int numPads = 8;
    int numIntergratedInst = 25; 
    bool stereoOut = true; 
    int samplingSpaceSec = 120;
    int numIntegratedFx = 12;

    void trigSnd ();
    void playSequence (int numSteps, int bpm, bool startSequence);
    void sendMidi (int midiNoteNum, int midiVel, bool noteEvent, bool isCc);
};

void SamplingPad::trigSnd(){}

void SamplingPad::playSequence(int numSteps, int bpm, bool startSequence)
{
    if (startSequence == 1)
    {
        numSteps *= bpm;
    }
    else
    {
        numSteps = 0;
    }
}

void SamplingPad::sendMidi(int midiNoteNum, int midiVel, bool noteEvent, bool isCc)
{
    midiNoteNum = 127;
    midiVel = 127;
    noteEvent = true;
    isCc = false;
}

struct AnalogConsole
{
    int numChannelStrips = 24;
    int numAudioSend = 2; 
    int numMonitorOut = 4;
    int numStereoChanels = 2;
    bool preFader = false;

    void mixSounds (int trackNum, float trackLvl, float pan); 
    void masterOut (float masterOutdB);
    void addTone (float hiFreq, float hiBoost, float midFreq, float midBoost, float bassFreq, float bassBoost);
};

void AnalogConsole::mixSounds(int trackNum, float trackLvl,float pan)
{
    trackNum = 1;
    trackLvl = -6.0f;
    pan = 0;
}

void AnalogConsole::masterOut(float masterOutdB = -6.0f)
{
    if (masterOutdB < -6.0f && masterOutdB > -12.0f )
    {
        masterOutdB = -6.0f;
    }
}

void AnalogConsole::addTone(float hiFreq, float hiBoost, float midFreq, float midBoost, float bassFreq, float bassBoost)
{
    hiFreq += hiBoost;
    midFreq += midBoost;
    bassFreq += bassBoost;
}

struct DawMixer
{
    int maxNumFaders = 175;
    float panPos = 0.0f; 
    float recBtnDiameter = 45.5f;
    float sliderLenght = 250.25f;
    int numInserts = 20;

    void recordReady ();
    void panSnd (float pan);
    void audioVolume (float laudioLvl);
};

void DawMixer::recordReady(){}

void DawMixer::panSnd(float pan)
{
    panPos += pan;
}

void DawMixer::audioVolume (float laudioLvl)
{
    laudioLvl = 1.0f;
}

struct VirtualMidiKey
{
    int numOctaves = 6; 
    int numMidiChanels = 32;
    int keyboardSize = 500; 
    bool invertKeyColour = false;
    int velocityRange = 127;

    void sendMidi (int keyIndex, int velocity);
    int displayMidi (char noteName);
    void receiveInputKey (int inputNum, int midiChanel);
};

void VirtualMidiKey::sendMidi(int keyIndex, int velocity)
{
    keyIndex -= 1;
    velocity -= 1;
}

int VirtualMidiKey::displayMidi(char noteName)
{
    return noteName;
}

void VirtualMidiKey::receiveInputKey(int inputNum, int midiChanel)
{
    inputNum = 0;
    midiChanel = 1;
}

struct ToolbarDocker
{
    int numDockerTools = 12;
    float toolSelectorSize = 25.5f;
    float dockerPosX = 255.0f;
    float dockerWidth = 500.0f;
    int numDockerRow = 2;

    void changeTool (int toolListIndex, int replaceIndex);
    void customizeTool (int indexSwitch, int newToolIndex);
    void activateMetronom (bool mentroPlay);
};

void ToolbarDocker::changeTool(int toolListIndex, int replaceIndex)
{
    toolListIndex = replaceIndex;   
}

void ToolbarDocker::customizeTool(int indexSwitch, int newToolIndex)
{
    indexSwitch = newToolIndex;
}

void ToolbarDocker::activateMetronom(bool mentroPlay)
{
   mentroPlay = true; 
}

struct PerformanceMeter
{
    float textSize = 17;
    float windowSize = 1080.0f;
    std::string fontStyle = "arial";
    std::string backGroundColor = "green";
    double cpuClockSpeed = 0.00025;

    void displayCpu (int posX, int posY, float width, float height,bool active, double cpuClock);
    void displayRam (int posX, int posY, float width, float height,bool active);
    void displayDiskRead (int posX, int posY, float width, float height,bool active);
};

void PerformanceMeter::displayCpu(int posX = 10, int posY = 10, float width = 250.0f, float height = 355.5f, bool active = true, double cpuClock = 0.00025)
{
    int numLines = 8;
    textSize = height/numLines;

    if(active)
    {
        width += posX;
        height += posY;
        windowSize = width*height;
        cpuClock = 0.02;
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
        width += posX;
        height += posY;
    }
    else
    {
        posX = 0;
        posY = 0;
    }

}

void PerformanceMeter::displayDiskRead(int posX, int posY, float width, float height, bool active)
{
     if (active)
    {
        width += posX;
        height += posY;
    }
    else
    {
        posX = 0;
        posY = 0;
    }
}

struct TempoEnv
{
    int bpm = 128;
    bool linearPointShape = true;
    int numPoints = 200;
    std::string tempoSignature = "7/8";
    std::string envLineColour = "purple";

    void changeBpm (int newBpm);
    void newPoint (float newPointPosX, float newPointPosY, bool pointShape); 
    void deletePoint (int pointIndex);
};

void TempoEnv::changeBpm(int newBpm)
{
    bpm = newBpm;
}

void TempoEnv::newPoint(float newPointPosX, float newPointPosY,bool pointShape)
{
    float floor = 0.01f;

    if (numPoints < 200 && pointShape == true)
    {
        newPointPosX = newPointPosX + floor;
        newPointPosY = newPointPosY + floor;
    }
    else
    {
        newPointPosX = 0;
        newPointPosY = 0;
    }

    
}

void TempoEnv::deletePoint(int pointIndex)
{
    pointIndex = 0;
}

struct DigitalWorkstation
{
    DawMixer mixer;
    VirtualMidiKey midiKeys;
    ToolbarDocker toolDocker;
    PerformanceMeter perfoMeter;
    TempoEnv tempoEnveloppe;

    struct TransportBar
    {
        bool transportBarShow = true;
        bool playBtnActive = false;
        bool showPlayRate = true;
        float sartTimeSelectionPoint = 0.0f;
        float endTimeSelectionPoint = 24.0f;

        void loopSelection(bool loopSelection);
        float tapTempoBpm (int numTap, float time);
        void moveCursorPos (int beat, int mesure);
    };

    void loopAudioSection (float loopIn, float loopOut);
    void recordData (int input, bool isMidi);
    void bounce (int tracks, float startingPoint, float endingPoint);
};

void DigitalWorkstation::loopAudioSection(float loopIn, float loopOut)
{
    loopIn -= loopOut;
}

void DigitalWorkstation::recordData(int input, bool isMidi){
    if (isMidi)
    {
        input = 1;
    }
    else
    {
        input = 0;
    }
}

void DigitalWorkstation::bounce(int tracks, float startingPoint, float endingPoint)
{
    tracks = tracks * 2;
    startingPoint += endingPoint;
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
    float newBpm;
    newBpm = numTap/time;

    return newBpm;
}

void DigitalWorkstation::TransportBar::moveCursorPos(int beat, int mesure)
{
    beat *= mesure;
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
    std::cout << "good to go!" << std::endl;
}
