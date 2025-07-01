
#define PYBIND11_DETAILED_ERROR_MESSAGE

#include "wgfmu.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>
#include <vector>


namespace py = pybind11;

int openSession(const char* address) {
    return WGFMU_openSession(address);
}
int closeSession() {
    return WGFMU_closeSession();
}
int initialize() {
    return WGFMU_initialize();
}
int setTimeout(double timeout) {
    return WGFMU_setTimeout(timeout);
}

py::tuple doSelfCalibration() {
    int result;
    int size = 256;
    char* detail = new char[size]; // pre-allocated buffer

    int rv;
    rv = WGFMU_doSelfCalibration(&result, detail, &size);

    if (rv != 0) {
        std::cerr << "WGFMU_doSelfCalibration Error Code: " << rv << std::endl;
    }

    std::string detail_str(detail, size);

    delete[] detail; // free the allocated buffer

    return py::make_tuple(result, detail_str);
}

py::tuple doSelfTest() {
    int result = 0;
    int size = 256; // max detail buffer size
    char *detail = new char[size]; // pre-allocated buffer

    int ret_code = WGFMU_doSelfTest(&result, detail, &size);

    if (ret_code != 0) {
        std::cerr << "WGFMU_doSelfTest Error Code: " << ret_code << std::endl;
    }

    // Convert char* buffer to std::string (ensure it's null-terminated)
    std::string detail_str(detail, size);

    delete[] detail; // free the allocated buffer

    return py::make_tuple(result, detail_str);
}

std::vector<int> getChannelIds() {
    int rv;
    int size;
    rv = WGFMU_getChannelIdSize(&size);

    if (rv != 0) {
        std::cerr << "WGFMU_getChannelIdSize Error Code: " << rv << std::endl;
        return {};
    }

    std::vector<int> channelIdsVec(size);
    
    rv = WGFMU_getChannelIds(channelIdsVec.data(), &size);

    if (rv != 0) {
        std::cerr << "WGFMU_getChannelIds Error Code: " << rv << std::endl;
    }

    return channelIdsVec;
}

std::string getError() {
    int size;
    int rv;
    rv = WGFMU_getErrorSize(&size);
    if (rv != 0) {
        std::cerr << "WGFMU_getErrorSize Error Code: " << rv << std::endl;
    }
    char* error = new char[size];
    rv = WGFMU_getError(error, &size);
    
    if (rv != 0) {
        std::cerr << "WGFMU_getError Error Code: " << rv << std::endl;
    }
    
    std::string error_str(error, size);

    delete[] error; // free the allocated buffer
    
    return error_str;
}

std::string getErrorSummary() {
    int size;
    int rv;
    rv = WGFMU_getErrorSummarySize(&size);

    if (rv != 0) {
        std::cerr << "WGFMU_getErrorSummarySize Error Code: " << rv << std::endl;
    }

    char* errorSummary = new char[size];

    rv = WGFMU_getErrorSummary(errorSummary, &size);

    if (rv != 0) {
        std::cerr << "WGFMU_getErrorSummary Error Code: " << rv << std::endl;
    }

    std::string errorSummary_str(errorSummary, size);

    delete[] errorSummary; // free the allocated buffer

    return errorSummary_str;
}

int treatWarningsAsErrors(int warningLevel) {
    return WGFMU_treatWarningsAsErrors(warningLevel);
}
int setWarningLevel(int warningLevel) {
    return WGFMU_setWarningLevel(warningLevel);
}
int getWarningLevel() {
    int warningLevel;
    int rv;

    rv = WGFMU_getWarningLevel(&warningLevel);

    if (rv != 0) {
        std::cerr << "WGFMU_getWarningLevel Error Code: " << rv << std::endl;
    }

    return warningLevel;
}

std::string getWarningSummary() {
    int rv;
    int size;
    rv = WGFMU_getWarningSummarySize(&size);

    if (rv != 0) {
        std::cerr << "WGFMU_getWarningSummarySize Error Code: " << rv << std::endl;
    }
    char* warningSummary = new char[size];
    rv = WGFMU_getWarningSummary(warningSummary, &size);

    if (rv != 0) {
        std::cerr << "WGFMU_getWarningSummary Error Code: " << rv << std::endl;
    }

    std::string warningSummary_str(warningSummary, size);

    delete[] warningSummary; // free the allocated buffer

    return warningSummary_str;
}

int openLogFile(const char* fileName) {
    return WGFMU_openLogFile(fileName);
}
int closeLogFile() {
    return WGFMU_closeLogFile();
}
int setOperationMode(int channelId, int operationMode) {
    return WGFMU_setOperationMode(channelId, operationMode);
}
int getOperationMode(int channelId) {
    int operationMode;
    int rv;

    rv = WGFMU_getOperationMode(channelId, &operationMode);

    if (rv != 0) {
        std::cerr << "WGFMU_getOperationMode Error Code: " << rv << std::endl;
    }

    return operationMode;
}
int setForceVoltageRange(int channelId, int forceVoltageRange) {
    return WGFMU_setForceVoltageRange(channelId, forceVoltageRange);
}

int getForceVoltageRange(int channelId) {
    int forceVoltageRange;
    int rv;
    rv = WGFMU_getForceVoltageRange(channelId, &forceVoltageRange);

    if (rv != 0) {
        std::cerr << "WGFMU_getForceVoltageRange Error Code: " << rv << std::endl;
    }

    return forceVoltageRange;
}

int setMeasureMode(int channelId, int measureMode) {
    return WGFMU_setMeasureMode(channelId, measureMode);
}

int getMeasureMode(int channelId) {
    int measureMode;
    int rv;
    rv = WGFMU_getMeasureMode(channelId, &measureMode);

    if (rv != 0) {
        std::cerr << "WGFMU_getMeasureMode Error Code: " << rv << std::endl;
    }

    return measureMode;
}

int setMeasureVoltageRange(int channelId, int measureVoltageRange) {
    return WGFMU_setMeasureVoltageRange(channelId, measureVoltageRange);
}
int getMeasureVoltageRange(int channelId) {
    int measureVoltageRange;
    int rv;
    rv = WGFMU_getMeasureVoltageRange(channelId, &measureVoltageRange);

    if (rv != 0) {
        std::cerr << "WGFMU_getMeasureVoltageRange Error Code: " << rv << std::endl;
    }

    return measureVoltageRange;

}
int setMeasureCurrentRange(int channelId, int measureCurrentRange) {
    return WGFMU_setMeasureCurrentRange(channelId, measureCurrentRange);
}

int getMeasureCurrentRange(int channelId) {
    int measureCurrentRange;
    int rv;
    rv = WGFMU_getMeasureCurrentRange(channelId, &measureCurrentRange);

    if (rv != 0) {
        std::cerr << "WGFMU_getMeasureCurrentRange Error Code: " << rv << std::endl;
    }

    return measureCurrentRange;
}

int setForceDelay(int channelId, double forceDelay) {
    return WGFMU_setForceDelay(channelId, forceDelay);
}

double getForceDelay(int channelId) {
    double forceDelay;
    int rv;
    rv = WGFMU_getForceDelay(channelId, &forceDelay);

    if (rv != 0) {
        std::cerr << "WGFMU_getForceDelay Error Code: " << rv << std::endl;
    }

    return forceDelay;
}

int setMeasureDelay(int channelId, double measureDelay) {
    return WGFMU_setMeasureDelay(channelId, measureDelay);
}

double getMeasureDelay(int channelId) {
    double measureDelay;
    int rv;

    rv = WGFMU_getMeasureDelay(channelId, &measureDelay);

    if (rv != 0) {
        std::cerr << "WGFMU_getMeasureDelay Error Code: " << rv << std::endl;
    }

    return measureDelay;
}

int setMeasureEnabled(int channelId, int measureEnabled) {
    return WGFMU_setMeasureEnabled(channelId, measureEnabled);
}

int isMeasureEnabled(int channelId) {
    int measureEnabled;
    int rv;
    rv = WGFMU_isMeasureEnabled(channelId, &measureEnabled);

    if (rv != 0) {
        std::cerr << "WGFMU_isMeasureEnabled Error Code: " << rv << std::endl;
    }

    return measureEnabled;
}
int setTriggerOutMode(int channelId, int triggerOutMode, int polarity) {
    return WGFMU_setTriggerOutMode(channelId, triggerOutMode, polarity);
}

py::tuple getTriggerOutMode(int channelId) {
    int triggerOutMode;
    int polarity;
    int rv;

    rv = WGFMU_getTriggerOutMode(channelId, &triggerOutMode, &polarity);

    if (rv != 0) {
        std::cerr << "WGFMU_getTriggerOutMode Error Code: " << rv << std::endl;
    }

    return py::make_tuple(triggerOutMode, polarity);
}

int connect(int channelId) {
    return WGFMU_connect(channelId);
}
int disconnect(int channelId) {
    return WGFMU_disconnect(channelId);
}
int clear() {
    return WGFMU_clear();
}
int createPattern(const char* patternName, double initialVoltage) {
    return WGFMU_createPattern(patternName, initialVoltage);
}
int addVector(const char* patternName, double deltaTime, double voltage) {
    return WGFMU_addVector(patternName, deltaTime, voltage);
}
int addVectors(const char* patternName, double* deltaTimes, double* voltages, int size) {
    return WGFMU_addVectors(patternName, deltaTimes, voltages, size);
}
int setVector(const char* patternName, double time, double voltage) {
    return WGFMU_setVector(patternName, time, voltage);
}
int setVectors(const char* patternName, std::vector<double> times, std::vector<double> voltages) {
    int size = times.size();

    return WGFMU_setVectors(patternName, times.data(), voltages.data(), size);
}
int createMergedPattern(const char* patternName, const char* pattern1, const char* pattern2, int axis) {
    return WGFMU_createMergedPattern(patternName, pattern1, pattern2, axis);
}
int createMultipliedPattern(const char* patternName, const char* pattern1, double timeFactor, double voltageFactor) {
    return WGFMU_createMultipliedPattern(patternName, pattern1, timeFactor, voltageFactor);
}
int createOffsetPattern(const char* patternName, const char* pattern1, double timeOffset, double voltageOffset) {
    return WGFMU_createOffsetPattern(patternName, pattern1, timeOffset, voltageOffset);
}
int setMeasureEvent(const char* patternName, const char* eventName, double time, int measurementPoints, double measurementInterval, double averagingTime, int rawData) {
    return WGFMU_setMeasureEvent(patternName, eventName, time, measurementPoints, measurementInterval, averagingTime, rawData);
}
int setRangeEvent(const char* patternName, const char* eventName, double time, int rangeIndex) {
    return WGFMU_setRangeEvent(patternName, eventName, time, rangeIndex);
}
int setTriggerOutEvent(const char* patternName, const char* eventName, double time, double duration) {
    return WGFMU_setTriggerOutEvent(patternName, eventName, time, duration);
}
int addSequence(int channelId, const char* patternName, double loopCount) {
    return WGFMU_addSequence(channelId, patternName, loopCount);
}
int addSequences(int channelId, const std::vector<std::string> patternNames, std::vector<double> loopCounts) {
    int size = patternNames.size();

    std::vector<const char*> patternNamesVec(size);
    double* d_loopCounts = new double[size];

    for (int i = 0; i < size; ++i) {
        patternNamesVec[i] = patternNames[i].c_str();
    }

    for (int i = 0; i < size; ++i) {
        d_loopCounts[i] = loopCounts[i];
    }

    const char **d_patternNames = patternNamesVec.data();
    return WGFMU_addSequences(channelId, d_patternNames, d_loopCounts, size);
}

py::tuple getPatternForceValues(const char* patternName, int offset) {
    int size;
    int rv;
    rv = WGFMU_getPatternForceValueSize(patternName, &size);

    if (rv != 0) {
        std::cerr << "WGFMU_getPatternForceValueSize Error Code: " << rv << std::endl;
    }

    std::vector<double> forceTimesVec(size);
    std::vector<double> forceValuesVec(size);
    rv = WGFMU_getPatternForceValues(patternName, offset, &size, forceTimesVec.data(), forceValuesVec.data());
    
    if (rv != 0) {
        std::cerr << "WGFMU_getPatternForceValues Error Code: " << rv << std::endl;
    }

    return py::make_tuple(forceTimesVec, forceValuesVec);
}

double getPatternInterpolatedForceValue(const char* patternName, double time) {
    double forceValue;
    int rv;
    rv = WGFMU_getPatternInterpolatedForceValue(patternName, time, &forceValue);

    if (rv != 0) {
        std::cerr << "WGFMU_getPatternInterpolatedForceValue Error Code: " << rv << std::endl;
    }

    return forceValue;
}

std::vector<double> getPatternMeasureTimes(const char* patternName) {
    int size;
    int rv;
    rv = WGFMU_getPatternMeasureTimeSize(patternName, &size);

    if (rv != 0) {
        std::cerr << "WGFMU_getPatternMeasureTimeSize Error Code: " << rv << std::endl;
    }

    if (size <= 0) {
        std::cerr << "No measure times available for pattern: " << patternName << std::endl;
    }

    double* measureTimes = new double[size];

    rv = WGFMU_getPatternMeasureTimes(patternName, 0, &size, measureTimes);

    if (rv != 0) {
        std::cerr << "WGFMU_getPatternMeasureTimes Error Code: " << rv << std::endl;
    }

    std::vector<double> measureTimesVec(size);

    for (int i = 0; i < size; ++i) {
        measureTimesVec[i] = measureTimes[i];
    }

    delete[] measureTimes;

    return measureTimesVec;
}

py::tuple getForceValues(int channelId, double offset) {
    double valueSize;
    int rv;

    rv = WGFMU_getForceValueSize(channelId, &valueSize);

    int size = int(valueSize);

    if (rv != 0) {
        std::cerr << "WGFMU_getForceValueSize Error Code: " << rv << std::endl;
    }

    std::vector<double> forceTimes(size);
    std::vector<double> forceValues(size);


    rv = WGFMU_getForceValues(channelId, offset, &size, forceTimes.data(), forceValues.data());

    if (rv != 0) {
        std::cerr << "WGFMU_getForceValues Error Code: " << rv << std::endl;
    }

    return py::make_tuple(forceTimes, forceValues);
}

double getInterpolatedForceValue(int channelId, double time) {
    double forceValue;
    int rv;

    rv = WGFMU_getInterpolatedForceValue(channelId, time, &forceValue);

    if (rv != 0) {
        std::cerr << "WGFMU_getInterpolatedForceValue Error Code: " << rv << std::endl;
    }

    return forceValue;
}

std::vector<double> getMeasureTimes(int channelId, int offset) {
    int size;
    int rv;
    rv = WGFMU_getMeasureTimeSize(channelId, &size);

    if (rv != 0) {
        std::cerr << "WGFMU_getMeasureTimeSize Error Code: " << rv << std::endl;
    }

    if (size <= 0) {
        std::cerr << "No measure times available for channel ID: " << channelId << std::endl;
    }

    double* measureTimes = new double[size];
    rv = WGFMU_getMeasureTimes(channelId, offset, &size, measureTimes);

    if (rv != 0) {
        std::cerr << "WGFMU_getMeasureTimes Error Code: " << rv << std::endl;
    }

    std::vector<double> measureTimesVec(size);
    for (int i = 0; i < size; ++i) {
        measureTimesVec[i] = measureTimes[i];
    }
    delete[] measureTimes;

    return measureTimesVec;
}

py::tuple getMeasureEvents(int channelId, int measureID) {
    int size;
    int rv;
    rv = WGFMU_getMeasureEventSize(channelId, &size);

    if (rv != 0) {
        std::cerr << "WGFMU_getMeasureEventSize Error Code: " << rv << std::endl;
    }

    int stringSize = 512;

    char** ptn = new char*[size];
    char** evt = new char*[size];
    for (int i = 0; i < size; ++i) {
        ptn[i] = new char[stringSize];
        evt[i] = new char[stringSize];
    }
    int* cycles = new int[size];
    double* loops = new double[size];
    int* counts = new int[size];
    int* idxs = new int[size];
    int* lens = new int[size];

    rv = WGFMU_getMeasureEvents(channelId, measureID, &size, ptn, evt, cycles, loops, counts, idxs, lens);

    if (rv != 0) {
        std::cerr << "WGFMU_getMeasureEvents Error Code: " << rv << std::endl;
    }

    std::vector<std::string> patternNames(size);
    std::vector<std::string> eventNames(size);
    std::vector<int> cyclesVec(size);
    std::vector<double> loopsVec(size);
    std::vector<int> countsVec(size);
    std::vector<int> idxsVec(size);
    std::vector<int> lensVec(size);

    for (int i = 0; i < size; ++i) {
        patternNames[i] = std::string(ptn[i]);
        eventNames[i] = std::string(evt[i]);
        cyclesVec[i] = cycles[i];
        loopsVec[i] = loops[i];
        countsVec[i] = counts[i];
        idxsVec[i] = idxs[i];
        lensVec[i] = lens[i];

        delete[] ptn[i];
        delete[] evt[i];
    }
    delete[] ptn;
    delete[] evt;
    delete[] cycles;
    delete[] loops;
    delete[] counts;
    delete[] idxs;
    delete[] lens;

    return py::make_tuple(patternNames, eventNames, cyclesVec, loopsVec, countsVec, idxsVec, lensVec);

}

py::tuple getMeasureEventAttribute(int channelId, int index) {
    double time;
    int measurementPoints;
    double measurementInterval;
    double averagingTime;
    int rawData;
    int rv;

    rv = WGFMU_getMeasureEventAttribute(channelId, index, &time, &measurementPoints, &measurementInterval, &averagingTime, &rawData);

    return py::make_tuple(time, measurementPoints, measurementInterval, averagingTime, rawData);
}

int exportAscii(const char* fileName) {
    return WGFMU_exportAscii(fileName);
}
int update() {
    return WGFMU_update();
}
int updateChannel(int channelId) {
    return WGFMU_updateChannel(channelId);
}
int execute() {
    return WGFMU_execute();
}
int abortabort() {
    return WGFMU_abort();
}
int abortChannel(int channelId) {
    return WGFMU_abortChannel(channelId);
}

py::tuple getStatus() {
    int status;
    double elapsedTime, totalTime;
    int rv;

    rv = WGFMU_getStatus(&status, &elapsedTime, &totalTime);

    if (rv != 0) {
        std::cerr << "WGFMU_getStatus Error Code: " << rv << std::endl;
    }

    return py::make_tuple(status, elapsedTime, totalTime);

}

py::tuple getChannelStatus(int channelId) {
    int status;
    double elapsedTime, totalTime;
    int rv;
    rv = WGFMU_getChannelStatus(channelId, &status, &elapsedTime, &totalTime);

    if (rv != 0) {
        std::cerr << "WGFMU_getChannelStatus Error Code: " << rv << std::endl;
    }

    return py::make_tuple(status, elapsedTime, totalTime);
}

int waitUntilCompleted() {
    return WGFMU_waitUntilCompleted();
}
py::tuple getMeasureValueSize(int channelId) {
    int rv, measuredSize, totalSize;

    rv = WGFMU_getMeasureValueSize(channelId, &measuredSize, &totalSize);

    return py::make_tuple(measuredSize, totalSize);
}

py::tuple getMeasureValues(int channelId) {
    int rv, measuredSize, totalSize;
    

    rv = WGFMU_getMeasureValueSize(channelId, &measuredSize, &totalSize);

    if (rv != 0) {
        std::cerr << "WGFMU_getMeasureValueSize Error Code: " << rv << std::endl;
    }

    std::vector<double> measureTimes;
    std::vector<double> measureValues;
    measureTimes.resize(measuredSize);
    measureValues.resize(measuredSize);

    std::cout << "measureSize" << measuredSize << std::endl;

    rv = WGFMU_getMeasureValues(channelId, 0, &measuredSize, measureTimes.data(), measureValues.data());

    if (rv != 0) {
        std::cerr << "WGFMU_getMeasureValues Error Code: " << rv << std::endl;
    }

    return py::make_tuple(measureTimes, measureValues);
}
int getMeasureValue(int channelId, int index, double* measureTime, double* measureValue) {
    return WGFMU_getMeasureValue(channelId, index, measureTime, measureValue);
}
int getCompletedMeasureEventSize(int channelId, int* measuredSize, int* totalSize) {
    return WGFMU_getCompletedMeasureEventSize(channelId, measuredSize, totalSize);
}

py::tuple isMeasureEventCompleted(int channelId, const char* patternName, const char* eventName, int cycle, double loop, int count) {
    int completed, index, offset, size;
    int rv;
    rv = WGFMU_isMeasureEventCompleted(channelId, patternName, eventName, cycle, loop, count, &completed, &index, &offset, &size);

    if (rv != 0) {
        std::cerr << "WGFMU_isMeasureEventCompleted Error Code: " << rv << std::endl;
    }


    return py::make_tuple(completed, index, offset, size);
}

int dcforceVoltage(int channelId, double voltage) {
    return WGFMU_dcforceVoltage(channelId, voltage);
}

double dcmeasureValue(int channelId) {
    double value;
    WGFMU_dcmeasureValue(channelId, &value);
    return value;
}

double dcmeasureAveragedValue(int channelId, int count, int interval) {
    double value;
    WGFMU_dcmeasureAveragedValue(channelId, count, interval, &value);
    return value;
}

enum OPERATION_MODE {
    DC = 2000,
    FAST_IV = 2001,
    PG = 2002,
    SMU = 2003
};

enum FORCE_VOLTAGE_RANGE {
    AUTO = 3000,
    _3V = 3001,
    _5V = 3002,
    _10V_NEGATIVE = 3003,
    _10V_POSITIVE = 3004
};

enum MEASURE_MODE {
    VOLTAGE = 4000,
    CURRENT = 4001
};

enum MEASURE_EVENT_DATA {
    AVERAGED = 12000,
    RAW = 12001,
};

PYBIND11_MODULE(WGFMUpy, m) {

    m.def("openSession", &openSession, R"pbdoc(
                openSession wgfmu
        )pbdoc");
    m.def("closeSession", &closeSession, R"pbdoc(
                closeSession wgfmu
        )pbdoc");
    m.def("initialize", &initialize, R"pbdoc(
                initialize wgfmu
        )pbdoc");
    m.def("setTimeout", &setTimeout, R"pbdoc(
                setTimeout wgfmu
        )pbdoc");
    m.def("doSelfCalibration", &doSelfCalibration, R"pbdoc(
                doSelfCalibration wgfmu
        )pbdoc");
    m.def("doSelfTest", &doSelfTest, R"pbdoc(
                doSelfTest wgfmu
        )pbdoc");
    m.def("getChannelIds", &getChannelIds, R"pbdoc(
                getChannelIds wgfmu
        )pbdoc");
    m.def("getError", &getError, R"pbdoc(
                getError wgfmu
        )pbdoc");
    m.def("getErrorSummary", &getErrorSummary, R"pbdoc(
                getErrorSummary wgfmu
        )pbdoc");
    m.def("treatWarningsAsErrors", &treatWarningsAsErrors, R"pbdoc(
                treatWarningsAsErrors wgfmu
        )pbdoc");
    m.def("setWarningLevel", &setWarningLevel, R"pbdoc(
                setWarningLevel wgfmu
        )pbdoc");
    m.def("getWarningLevel", &getWarningLevel, R"pbdoc(
                getWarningLevel wgfmu
        )pbdoc");
    m.def("getWarningSummary", &getWarningSummary, R"pbdoc(
                getWarningSummary wgfmu
        )pbdoc");
    m.def("openLogFile", &openLogFile, R"pbdoc(
                openLogFile wgfmu
        )pbdoc");
    m.def("closeLogFile", &closeLogFile, R"pbdoc(
                closeLogFile wgfmu
        )pbdoc");
    m.def("setOperationMode", &setOperationMode, R"pbdoc(
                setOperationMode wgfmu
        )pbdoc");
    m.def("getOperationMode", &getOperationMode, R"pbdoc(
                getOperationMode wgfmu
        )pbdoc");
    m.def("setForceVoltageRange", &setForceVoltageRange, R"pbdoc(
                setForceVoltageRange wgfmu
        )pbdoc");
    m.def("getForceVoltageRange", &getForceVoltageRange, R"pbdoc(
                getForceVoltageRange wgfmu
        )pbdoc");
    m.def("setMeasureMode", &setMeasureMode, R"pbdoc(
                setMeasureMode wgfmu
        )pbdoc");
    m.def("getMeasureMode", &getMeasureMode, R"pbdoc(
                getMeasureMode wgfmu
        )pbdoc");
    m.def("setMeasureVoltageRange", &setMeasureVoltageRange, R"pbdoc(
                setMeasureVoltageRange wgfmu
        )pbdoc");
    m.def("getMeasureVoltageRange", &getMeasureVoltageRange, R"pbdoc(
                getMeasureVoltageRange wgfmu
        )pbdoc");
    m.def("setMeasureCurrentRange", &setMeasureCurrentRange, R"pbdoc(
                setMeasureCurrentRange wgfmu
        )pbdoc");
    m.def("getMeasureCurrentRange", &getMeasureCurrentRange, R"pbdoc(
                getMeasureCurrentRange wgfmu
        )pbdoc");
    m.def("setForceDelay", &setForceDelay, R"pbdoc(
                setForceDelay wgfmu
        )pbdoc");
    m.def("getForceDelay", &getForceDelay, R"pbdoc(
                getForceDelay wgfmu
        )pbdoc");
    m.def("setMeasureDelay", &setMeasureDelay, R"pbdoc(
                setMeasureDelay wgfmu
        )pbdoc");
    m.def("getMeasureDelay", &getMeasureDelay, R"pbdoc(
                getMeasureDelay wgfmu
        )pbdoc");
    m.def("setMeasureEnabled", &setMeasureEnabled, R"pbdoc(
                setMeasureEnabled wgfmu
        )pbdoc");
    m.def("isMeasureEnabled", &isMeasureEnabled, R"pbdoc(
                isMeasureEnabled wgfmu
        )pbdoc");
    m.def("setTriggerOutMode", &setTriggerOutMode, R"pbdoc(
                setTriggerOutMode wgfmu
        )pbdoc");
    m.def("getTriggerOutMode", &getTriggerOutMode, R"pbdoc(
                getTriggerOutMode wgfmu
        )pbdoc");
    m.def("connect", &connect, R"pbdoc(
                connect wgfmu
        )pbdoc");
    m.def("disconnect", &disconnect, R"pbdoc(
                disconnect wgfmu
        )pbdoc");
    m.def("clear", &clear, R"pbdoc(
                clear wgfmu
        )pbdoc");
    m.def("createPattern", &createPattern, R"pbdoc(
                createPattern wgfmu
        )pbdoc");
    m.def("addVector", &addVector, R"pbdoc(
                addVector wgfmu
        )pbdoc");
    m.def("addVectors", &addVectors, R"pbdoc(
                addVectors wgfmu
        )pbdoc");
    m.def("setVector", &setVector, R"pbdoc(
                setVector wgfmu
        )pbdoc");
    m.def("setVectors", &setVectors, R"pbdoc(
                setVectors wgfmu
        )pbdoc");
    m.def("createMergedPattern", &createMergedPattern, R"pbdoc(
                createMergedPattern wgfmu
        )pbdoc");
    m.def("createMultipliedPattern", &createMultipliedPattern, R"pbdoc(
                createMultipliedPattern wgfmu
        )pbdoc");
    m.def("createOffsetPattern", &createOffsetPattern, R"pbdoc(
                createOffsetPattern wgfmu
        )pbdoc");
    m.def("setMeasureEvent", &setMeasureEvent, R"pbdoc(
                setMeasureEvent wgfmu
        )pbdoc");
    m.def("setRangeEvent", &setRangeEvent, R"pbdoc(
                setRangeEvent wgfmu
        )pbdoc");
    m.def("setTriggerOutEvent", &setTriggerOutEvent, R"pbdoc(
                setTriggerOutEvent wgfmu
        )pbdoc");
    m.def("addSequence", &addSequence, R"pbdoc(
                addSequence wgfmu
        )pbdoc");
    m.def("addSequences", &addSequences, R"pbdoc(
                addSequences wgfmu
        )pbdoc");
    m.def("getPatternForceValues", &getPatternForceValues, R"pbdoc(
                getPatternForceValues wgfmu
        )pbdoc");
    m.def("getPatternInterpolatedForceValue", &getPatternInterpolatedForceValue, R"pbdoc(
                getPatternInterpolatedForceValue wgfmu
        )pbdoc");
    m.def("getPatternMeasureTimes", &getPatternMeasureTimes, R"pbdoc(
                getPatternMeasureTimes wgfmu
        )pbdoc");
    m.def("getForceValues", &getForceValues, R"pbdoc(
                getForceValues wgfmu
        )pbdoc");
    m.def("getInterpolatedForceValue", &getInterpolatedForceValue, R"pbdoc(
                getInterpolatedForceValue wgfmu
        )pbdoc");
    m.def("getMeasureTimes", &getMeasureTimes, R"pbdoc(
                getMeasureTimes wgfmu
        )pbdoc");
    m.def("getMeasureEvents", &getMeasureEvents, R"pbdoc(
                getMeasureEvents wgfmu
        )pbdoc");
    m.def("getMeasureEventAttribute", &getMeasureEventAttribute, R"pbdoc(
                getMeasureEventAttribute wgfmu
        )pbdoc");
    m.def("exportAscii", &exportAscii, R"pbdoc(
                exportAscii wgfmu
        )pbdoc");
    m.def("update", &update, R"pbdoc(
                update wgfmu
        )pbdoc");
    m.def("updateChannel", &updateChannel, R"pbdoc(
                updateChannel wgfmu
        )pbdoc");
    m.def("execute", &execute, R"pbdoc(
                execute wgfmu
        )pbdoc");
    m.def("abort", &abortabort, R"pbdoc(
                abort wgfmu
        )pbdoc");
    m.def("abortChannel", &abortChannel, R"pbdoc(
                abortChannel wgfmu
        )pbdoc");
    m.def("getStatus", &getStatus, R"pbdoc(
                getStatus wgfmu
        )pbdoc");
    m.def("getChannelStatus", &getChannelStatus, R"pbdoc(
                getChannelStatus wgfmu
        )pbdoc");
    m.def("waitUntilCompleted", &waitUntilCompleted, R"pbdoc(
                waitUntilCompleted wgfmu
        )pbdoc");
    m.def("getMeasureValueSize", &getMeasureValueSize, R"pbdoc(
                getMeasureValueSize wgfmu
        )pbdoc");
    m.def("getMeasureValues", &getMeasureValues, R"pbdoc(
                getMeasureValues wgfmu
        )pbdoc");
    m.def("getMeasureValue", &getMeasureValue, R"pbdoc(
                getMeasureValue wgfmu
        )pbdoc");
    m.def("getCompletedMeasureEventSize", &getCompletedMeasureEventSize, R"pbdoc(
                getCompletedMeasureEventSize wgfmu
        )pbdoc");
    m.def("isMeasureEventCompleted", &isMeasureEventCompleted, R"pbdoc(
                isMeasureEventCompleted wgfmu
        )pbdoc");
    m.def("dcforceVoltage", &dcforceVoltage, R"pbdoc(
                dcforceVoltage wgfmu
        )pbdoc");
    m.def("dcmeasureValue", &dcmeasureValue, R"pbdoc(
                dcmeasureValue wgfmu
        )pbdoc");
    m.def("dcmeasureAveragedValue", &dcmeasureAveragedValue, R"pbdoc(
                dcmeasureAveragedValue wgfmu
        )pbdoc");

    m.attr("WGFMU_NO_ERROR") = py::cast(WGFMU_NO_ERROR);
	m.attr("WGFMU_PARAMETER_OUT_OF_RANGE_ERROR") = py::cast(WGFMU_PARAMETER_OUT_OF_RANGE_ERROR);
	m.attr("WGFMU_ILLEGAL_STRING_ERROR") = py::cast(WGFMU_ILLEGAL_STRING_ERROR);
	m.attr("WGFMU_CONTEXT_ERROR") = py::cast(WGFMU_CONTEXT_ERROR);
	m.attr("WGFMU_FUNCTION_NOT_SUPPORTED_ERROR") = py::cast(WGFMU_FUNCTION_NOT_SUPPORTED_ERROR);
	m.attr("WGFMU_COMMUNICATION_ERROR") = py::cast(WGFMU_COMMUNICATION_ERROR);
	m.attr("WGFMU_FW_ERROR") = py::cast(WGFMU_FW_ERROR);
	m.attr("WGFMU_LIBRARY_ERROR") = py::cast(WGFMU_LIBRARY_ERROR);
	m.attr("WGFMU_ERROR") = py::cast(WGFMU_ERROR);
	m.attr("WGFMU_CHANNEL_NOT_FOUND_ERROR") = py::cast(WGFMU_CHANNEL_NOT_FOUND_ERROR);
	m.attr("WGFMU_PATTERN_NOT_FOUND_ERROR") = py::cast(WGFMU_PATTERN_NOT_FOUND_ERROR);
	m.attr("WGFMU_EVENT_NOT_FOUND_ERROR") = py::cast(WGFMU_EVENT_NOT_FOUND_ERROR);
	m.attr("WGFMU_PATTERN_ALREADY_EXISTS_ERROR") = py::cast(WGFMU_PATTERN_ALREADY_EXISTS_ERROR);
	m.attr("WGFMU_SEQUENCER_NOT_RUNNING_ERROR") = py::cast(WGFMU_SEQUENCER_NOT_RUNNING_ERROR);
	m.attr("WGFMU_RESULT_NOT_READY_ERROR") = py::cast(WGFMU_RESULT_NOT_READY_ERROR);
	m.attr("WGFMU_RESULT_OUT_OF_DATE") = py::cast(WGFMU_RESULT_OUT_OF_DATE);
	m.attr("WGFMU_ERROR_CODE_MIN") = py::cast(WGFMU_ERROR_CODE_MIN);
	m.attr("WGFMU_PASS") = py::cast(WGFMU_PASS);
	m.attr("WGFMU_FAIL") = py::cast(WGFMU_FAIL);

	m.attr("WGFMU_WARNING_LEVEL_OFFSET") = py::cast(WGFMU_WARNING_LEVEL_OFFSET);
	m.attr("WGFMU_WARNING_LEVEL_OFF") = py::cast(WGFMU_WARNING_LEVEL_OFF);
	m.attr("WGFMU_WARNING_LEVEL_SEVERE") = py::cast(WGFMU_WARNING_LEVEL_SEVERE);
	m.attr("WGFMU_WARNING_LEVEL_NORMAL") = py::cast(WGFMU_WARNING_LEVEL_NORMAL);
	m.attr("WGFMU_WARNING_LEVEL_INFORMATION") = py::cast(WGFMU_WARNING_LEVEL_INFORMATION);

    py::enum_<OPERATION_MODE>(m, "OPERATION_MODE")
        .value("DC", OPERATION_MODE::DC)
        .value("FASTIV", OPERATION_MODE::FAST_IV)
        .value("PG", OPERATION_MODE::PG)
        .value("SMU", OPERATION_MODE::SMU)
        .export_values();

    py::enum_<FORCE_VOLTAGE_RANGE>(m, "FORCE_VOLTAGE_RANGE")
        .value("AUTO", FORCE_VOLTAGE_RANGE::AUTO)
        .value("3V", FORCE_VOLTAGE_RANGE::_3V)
        .value("5V", FORCE_VOLTAGE_RANGE::_5V)
        .value("10V_NEGATIVE", FORCE_VOLTAGE_RANGE::_10V_NEGATIVE)
        .value("10V_POSITIVE", FORCE_VOLTAGE_RANGE::_10V_POSITIVE)
        .export_values();

    py::enum_<MEASURE_MODE>(m, "MEASURE_MODE")
        .value("VOLTAGE", MEASURE_MODE::VOLTAGE)
        .value("CURRENT", MEASURE_MODE::CURRENT)
        .export_values();

	m.attr("WGFMU_MEASURE_VOLTAGE_RANGE_OFFSET") = py::cast(WGFMU_MEASURE_VOLTAGE_RANGE_OFFSET);
	m.attr("WGFMU_MEASURE_VOLTAGE_RANGE_5V") = py::cast(WGFMU_MEASURE_VOLTAGE_RANGE_5V);
	m.attr("WGFMU_MEASURE_VOLTAGE_RANGE_10V") = py::cast(WGFMU_MEASURE_VOLTAGE_RANGE_10V);

	m.attr("WGFMU_MEASURE_CURRENT_RANGE_OFFSET") = py::cast(WGFMU_MEASURE_CURRENT_RANGE_OFFSET);
	m.attr("WGFMU_MEASURE_CURRENT_RANGE_1UA") = py::cast(WGFMU_MEASURE_CURRENT_RANGE_1UA);
	m.attr("WGFMU_MEASURE_CURRENT_RANGE_10UA") = py::cast(WGFMU_MEASURE_CURRENT_RANGE_10UA);
	m.attr("WGFMU_MEASURE_CURRENT_RANGE_100UA") = py::cast(WGFMU_MEASURE_CURRENT_RANGE_100UA);
	m.attr("WGFMU_MEASURE_CURRENT_RANGE_1MA") = py::cast(WGFMU_MEASURE_CURRENT_RANGE_1MA);
	m.attr("WGFMU_MEASURE_CURRENT_RANGE_10MA") = py::cast(WGFMU_MEASURE_CURRENT_RANGE_10MA);

	m.attr("WGFMU_MEASURE_ENABLED_OFFSET") = py::cast(WGFMU_MEASURE_ENABLED_OFFSET);
	m.attr("WGFMU_MEASURE_ENABLED_DISABLE") = py::cast(WGFMU_MEASURE_ENABLED_DISABLE);
	m.attr("WGFMU_MEASURE_ENABLED_ENABLE") = py::cast(WGFMU_MEASURE_ENABLED_ENABLE);
	m.attr("WGFMU_TRIGGER_OUT_MODE_OFFSET") = py::cast(WGFMU_TRIGGER_OUT_MODE_OFFSET);
	m.attr("WGFMU_TRIGGER_OUT_MODE_DISABLE") = py::cast(WGFMU_TRIGGER_OUT_MODE_DISABLE);
	m.attr("WGFMU_TRIGGER_OUT_MODE_START_EXECUTION") = py::cast(WGFMU_TRIGGER_OUT_MODE_START_EXECUTION);
	m.attr("WGFMU_TRIGGER_OUT_MODE_START_SEQUENCE") = py::cast(WGFMU_TRIGGER_OUT_MODE_START_SEQUENCE);
	m.attr("WGFMU_TRIGGER_OUT_MODE_START_PATTERN") = py::cast(WGFMU_TRIGGER_OUT_MODE_START_PATTERN);
	m.attr("WGFMU_TRIGGER_OUT_MODE_EVENT") = py::cast(WGFMU_TRIGGER_OUT_MODE_EVENT);

	m.attr("WGFMU_TRIGGER_OUT_POLARITY_OFFSET") = py::cast(WGFMU_TRIGGER_OUT_POLARITY_OFFSET);
	m.attr("WGFMU_TRIGGER_OUT_POLARITY_POSITIVE") = py::cast(WGFMU_TRIGGER_OUT_POLARITY_POSITIVE);
	m.attr("WGFMU_TRIGGER_OUT_POLARITY_NEGATIVE") = py::cast(WGFMU_TRIGGER_OUT_POLARITY_NEGATIVE);

	m.attr("WGFMU_AXIS_OFFSET") = py::cast(WGFMU_AXIS_OFFSET);
	m.attr("WGFMU_AXIS_TIME") = py::cast(WGFMU_AXIS_TIME);
	m.attr("WGFMU_AXIS_VOLTAGE") = py::cast(WGFMU_AXIS_VOLTAGE);

	m.attr("WGFMU_STATUS_OFFSET") = py::cast(WGFMU_STATUS_OFFSET);
	m.attr("WGFMU_STATUS_COMPLETED") = py::cast(WGFMU_STATUS_COMPLETED);
	m.attr("WGFMU_STATUS_DONE") = py::cast(WGFMU_STATUS_DONE);
	m.attr("WGFMU_STATUS_RUNNING") = py::cast(WGFMU_STATUS_RUNNING);
	m.attr("WGFMU_STATUS_ABORT_COMPLETED") = py::cast(WGFMU_STATUS_ABORT_COMPLETED);
	m.attr("WGFMU_STATUS_ABORTED") = py::cast(WGFMU_STATUS_ABORTED);
	m.attr("WGFMU_STATUS_RUNNING_ILLEGAL") = py::cast(WGFMU_STATUS_RUNNING_ILLEGAL);
	m.attr("WGFMU_STATUS_IDLE") = py::cast(WGFMU_STATUS_IDLE);

	m.attr("WGFMU_MEASURE_EVENT_OFFSET") = py::cast(WGFMU_MEASURE_EVENT_OFFSET);
	m.attr("WGFMU_MEASURE_EVENT_NOT_COMPLETED") = py::cast(WGFMU_MEASURE_EVENT_NOT_COMPLETED);
	m.attr("WGFMU_MEASURE_EVENT_COMPLETED") = py::cast(WGFMU_MEASURE_EVENT_COMPLETED);

    py::enum_<MEASURE_EVENT_DATA>(m, "MEASURE_EVENT_DATA")
        .value("AVERAGED", MEASURE_EVENT_DATA::AVERAGED)
        .value("RAW", MEASURE_EVENT_DATA::RAW)
        .export_values();
        
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}