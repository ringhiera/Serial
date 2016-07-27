##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Serial
ConfigurationName      :=Debug
WorkspacePath          := "/home/impe/Arduino/dev/hamming/Hamming_7_4"
ProjectPath            := "/home/impe/Arduino/dev/serial/Serial"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=impe
Date                   :=28/07/16
CodeLitePath           :="/home/impe/.codelite"
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Serial.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Serial.cpp$(ObjectSuffix) $(IntermediateDirectory)/RingBuffer.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/impe/Arduino/dev/serial/Serial/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Serial.cpp$(ObjectSuffix): Serial.cpp $(IntermediateDirectory)/Serial.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/impe/Arduino/dev/serial/Serial/Serial.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Serial.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Serial.cpp$(DependSuffix): Serial.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Serial.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Serial.cpp$(DependSuffix) -MM "Serial.cpp"

$(IntermediateDirectory)/Serial.cpp$(PreprocessSuffix): Serial.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Serial.cpp$(PreprocessSuffix) "Serial.cpp"

$(IntermediateDirectory)/RingBuffer.cpp$(ObjectSuffix): RingBuffer.cpp $(IntermediateDirectory)/RingBuffer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/impe/Arduino/dev/serial/Serial/RingBuffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RingBuffer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RingBuffer.cpp$(DependSuffix): RingBuffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RingBuffer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RingBuffer.cpp$(DependSuffix) -MM "RingBuffer.cpp"

$(IntermediateDirectory)/RingBuffer.cpp$(PreprocessSuffix): RingBuffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RingBuffer.cpp$(PreprocessSuffix) "RingBuffer.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


