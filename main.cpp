/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{

struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};

struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(1, 3);        //5) 
    
    std::cout << "\nbar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()


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

    void echoFunction (int treshold)
    {
        float delayTime = 0.0f;
        
        for (int i = 0; i <= treshold; i++)
        {
            delayTime += treshold;
            std::cout << i << " " << "delayTime : " << delayTime <<std::endl; 
        }
    }
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
    int numSpeakers;
    float speakerSize;
    float masterLvl;
    int ampModelingPresets;
    float fxvl;

    SolideStateAmp() : numSpeakers(4), speakerSize(12.0f), masterLvl(9.5f), ampModelingPresets(87), fxvl(5.5f){}   

    void signalProcessing (bool processSignal, int sampleStart, int sampleEnd);
    void imitateTubeAmp (int ampSelectIndex, std::string speakerIr); 
    void amplifieSound (int inputSig, float gain);

    float volumeLevel (float maxVolume)
    {
        float volLevel {0.f};

        while(volLevel < maxVolume)
        {
            volLevel += 0.5f;
            if (volLevel >= 11)
            {
                std::cout << volLevel << " is too loud,max at 11.0" << std::endl;
                break;
            }
        }
        return volLevel;
    }
};

void SolideStateAmp::signalProcessing(bool processSignal, int sampleStart, int sampleEnd)
{
   sampleEnd = (processSignal != 1) ? 0 : 1 + sampleStart;

   std::cout << " \nSolideStateAmp::signalProcessing ampModelingPresets: " << ampModelingPresets << " \nsampleEnd: " << sampleEnd << std::endl;
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

    void mixSounds (int trackNum, float trackLvl, float pan)
    {
        selectedCh = trackNum + 1;
        outputGain = trackLvl * -6.0f;
        panner = pan - 1;

        std::cout << "\nAnalogConsole::mixSounds preFader: " << preFader << "\n" << std::endl;

    }
    void masterOut (float masterOutdB);
    float addTone (float hiFreq, float hiBoost, float midFreq, float midBoost, float bassFreq, float bassBoost);
};

AnalogConsole::AnalogConsole() : numChannelStrips(127), numAudioSend(24), numMonitorOut(2), numStereoChanels(4), selectedCh(1), panner(0.0f), outputGain(1.0f), preFader(false){}

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
    
    int maxNumFaders {99};
    float panPos {0.0f}; 
    float recBtnDiameter {50.0f};
    float sliderLenght {100.0f};
    float lvl {55.25f};
    int numInserts {4};
    
    DawMixer();
    
    void recordReady ();
    void panSnd (float pan);
    void audioVolume (float laudioLvl, float normalize);
};

DawMixer::DawMixer(){}

void DawMixer::recordReady()
{
    std::cout << "\nDawMixer::recordReady numInserts : " << numInserts << "\n" << std::endl;
}

void DawMixer::panSnd(float pan)
{
    panPos += pan;

    std::cout << "\nDawMixer::panSnd panPos : " << panPos << "\n" << std::endl;
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
    void receiveInputKey (int inputNum, int midiChanel);
    
    int displayMidi (char noteName)
    {
        std::cout << "\nVirtualMidiKey::displayMidi numOctaves : " << numOctaves << "\n" << std::endl;
        
        return noteName;
    }
    
};

VirtualMidiKey::VirtualMidiKey()
{
    numOctaves = 8; 
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

    struct DefaultMainWindow
    {
        float w;
        float h;
        DefaultMainWindow() : w(1920.f), h(1080.f){}
    };

    void displayCpu (int posX, int posY, float width, float height,bool active, double cpuClock);
    void displayRam (int posX, int posY, float width, float height,bool active);
    void displayDiskRead (int posX, int posY, float width, float height,bool active);

    void isWindowToBig (float myWindowH, float myWindowW)
    {
        DefaultMainWindow window;
        
        for (int i = 0 ; i <  myWindowW; i++)
        {
            if (i > window.w)
            {
                std::cout << "resizing window width to : " << myWindowW << std::endl;
                window.w = myWindowW;
                break;
            }
        }

        for (int i = 0 ; i <  myWindowH; i++)
        {
            if (i > window.h)
            {
                std::cout << "resizing window height to : " << myWindowH << std::endl;
                window.h = myWindowH;
                break;
            }
        }
    }
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


/* 

//TESTS LEARNING STUFF

struct Type
{
    int typeVal;
    Type(int n) : typeVal(n){}
    
};

struct Test
{
    Type function(int val, int mul)
    {
        Type type (val * mul);
        return type.typeVal;
    }
};

struct Type_2
{
    int typeVal;
    int typeVal_2;
    Type_2(int n) : typeVal(n),typeVal_2 (n*2) {}
};

struct Test_2
{
    Type_2 fonction(int a, int b)
    {
        std::cout << "a : " << a << "\n" << "b : " << b << std::endl;
        return Type_2(a+b);
    }
};
*/


#include <iostream>
int main()
{

    /*
    Test test;
    auto type = test.function(28,2);
    std::cout << "\ntest.function " << type.typeVal << std::endl;

    Test_2 test_2;
    auto type_2 = test_2.fonction(1, 2);
    std::cout << "\ntest_2.fonction " << type_2.typeVal << std::endl;

    std::cout << "\ntest_2.fonction " << type_2.typeVal_2 << std::endl;
    */
    
    Example::main();
    EchoMachine echoMch;
    EchoMachine::Overdrive overDr;
    SamplingPad sampPad;
    SolideStateAmp solidAmp;
    AnalogConsole aConsol;
    DawMixer dawMix;
    VirtualMidiKey midiKey;

    PerformanceMeter perfoMeter;

    perfoMeter.isWindowToBig(1080, 1920);
    perfoMeter.isWindowToBig(2160, 3840);
    
    /*
    solidAmp.signalProcessing(true,0,20);
    aConsol.mixSounds(2, 0.5f, 0.0);
    dawMix.recordReady();
    dawMix.panSnd(0.0);
    midiKey.displayMidi('a');
    
    echoMch.distorSignal();
    overDr.filterSig (0, 1.0,500.50f, 'a');
    sampPad.playSequence(8, 120, true);

    std::cout << "EchoMachine echoMch " << (echoMch.outputLvl <= 0.0f ? "not loud enough" : "louder!!!!") << "\n";

    std::cout << "EchoMachine::Overdrive overDr = " << (overDr.clippingPoint <= 0.0f ? " need more Clipping...pleasee!!!" : "YASSSSS") << "\n";
    */

    echoMch.echoFunction(15);
    
    float lvl1 = solidAmp.volumeLevel(15.0f);
    float lvl2 = solidAmp.volumeLevel(8.5f);

    std::cout << "amp level 1 : " << lvl1 << std::endl;
    std::cout << "amp level 2 : " << lvl2 << std::endl;

    std::cout << "good to go!" << std::endl;
}
