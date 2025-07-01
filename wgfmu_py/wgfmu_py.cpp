
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
int doSelfCalibration(int* result, char* detail, int* size) {
    return WGFMU_doSelfCalibration(result, detail, size);
}

py::tuple doSelfTest() {
    int result = 0;
    int size = 1024; // max detail buffer size (change if needed)
    std::vector<char> detail(size, 0);  // pre-allocated buffer

    int ret_code = WGFMU_doSelfTest(&result, detail.data(), &size);

    // Convert char* buffer to std::string (ensure it’s null-terminated)
    std::string detail_str(detail.data(), strnlen(detail.data(), size));

    return py::make_tuple(ret_code, result, detail_str, size);
}



int getChannelIdSize(int size) {
    return WGFMU_getChannelIdSize(&size);
}
int getChannelIds(int* channelIds, int* size) {
    return WGFMU_getChannelIds(channelIds, size);
}
int getErrorSize(int* size) {
    return WGFMU_getErrorSize(size);
}
int getError(char* error, int* size) {
    return WGFMU_getError(error, size);
}
int getErrorSummarySize(int* size) {
    return WGFMU_getErrorSummarySize(size);
}
int getErrorSummary(char* errorSummary, int* size) {
    return WGFMU_getErrorSummary(errorSummary, size);
}
int treatWarningsAsErrors(int warningLevel) {
    return WGFMU_treatWarningsAsErrors(warningLevel);
}
int setWarningLevel(int warningLevel) {
    return WGFMU_setWarningLevel(warningLevel);
}
int getWarningLevel(int* warningLevel) {
    return WGFMU_getWarningLevel(warningLevel);
}
int getWarningSummarySize(int* size) {
    return WGFMU_getWarningSummarySize(size);
}
int getWarningSummary(char* warningSummary, int* size) {
    return WGFMU_getWarningSummary(warningSummary, size);
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
int getOperationMode(int channelId, int* operationMode) {
    return WGFMU_getOperationMode(channelId, operationMode);
}
int setForceVoltageRange(int channelId, int forceVoltageRange) {
    return WGFMU_setForceVoltageRange(channelId, forceVoltageRange);
}
int getForceVoltageRange(int channelId, int* forceVoltageRange) {
    return WGFMU_getForceVoltageRange(channelId, forceVoltageRange);
}
int setMeasureMode(int channelId, int measureMode) {
    return WGFMU_setMeasureMode(channelId, measureMode);
}
int getMeasureMode(int channelId, int measureMode) {
    int* measureMode_p = &measureMode;
    return WGFMU_getMeasureMode(channelId, measureMode_p);
}
int setMeasureVoltageRange(int channelId, int measureVoltageRange) {
    return WGFMU_setMeasureVoltageRange(channelId, measureVoltageRange);
}
int getMeasureVoltageRange(int channelId, int* measureVoltageRange) {
    return WGFMU_getMeasureVoltageRange(channelId, measureVoltageRange);
}
int setMeasureCurrentRange(int channelId, int measureCurrentRange) {
    return WGFMU_setMeasureCurrentRange(channelId, measureCurrentRange);
}
int getMeasureCurrentRange(int channelId, int* measureCurrentRange) {
    return WGFMU_getMeasureCurrentRange(channelId, measureCurrentRange);
}
int setForceDelay(int channelId, double forceDelay) {
    return WGFMU_setForceDelay(channelId, forceDelay);
}
int getForceDelay(int channelId, double* forceDelay) {
    return WGFMU_getForceDelay(channelId, forceDelay);
}
int setMeasureDelay(int channelId, double measureDelay) {
    return WGFMU_setMeasureDelay(channelId, measureDelay);
}
int getMeasureDelay(int channelId, double* measureDelay) {
    return WGFMU_getMeasureDelay(channelId, measureDelay);
}
int setMeasureEnabled(int channelId, int measureEnabled) {
    return WGFMU_setMeasureEnabled(channelId, measureEnabled);
}
int isMeasureEnabled(int channelId, int* measureEnabled) {
    return WGFMU_isMeasureEnabled(channelId, measureEnabled);
}
int setTriggerOutMode(int channelId, int triggerOutMode, int polarity) {
    return WGFMU_setTriggerOutMode(channelId, triggerOutMode, polarity);
}
int getTriggerOutMode(int channelId, int* triggerOutMode, int* polarity) {
    return WGFMU_getTriggerOutMode(channelId, triggerOutMode, polarity);
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
int setVectors(const char* patternName, double* times, double* voltages, int size) {
    return WGFMU_setVectors(patternName, times, voltages, size);
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
int addSequences(int channelId, const std::vector<std::string> patternNames, double* loopCounts, int size) {
    std::vector<const char*> cstrs2;
    for (auto& str : patternNames) {
        cstrs2.push_back(const_cast<const char*>(str.c_str()));
    }

    // Optional: Add a nullptr terminator if the API expects a null-terminated list
    // cstrs.push_back(nullptr);

    // Get the char** pointer
    const char** d_patternNames = cstrs2.data();
    return WGFMU_addSequences(channelId, d_patternNames, loopCounts, size);
}
int getPatternForceValueSize(const char* patternName, int* size) {
    return WGFMU_getPatternForceValueSize(patternName, size);
}
int getPatternForceValues(const char* patternName, int offset, int* size, double* forceTimes, double* forceValues) {
    return WGFMU_getPatternForceValues(patternName, offset, size, forceTimes, forceValues);
}
int getPatternForceValue(const char* patternName, int index, double* forceTime, double* forceValue) {
    return WGFMU_getPatternForceValue(patternName, index, forceTime, forceValue);
}
int getPatternInterpolatedForceValue(const char* patternName, double time, double* forceValue) {
    return WGFMU_getPatternInterpolatedForceValue(patternName, time, forceValue);
}
int getPatternMeasureTimeSize(const char* patternName, int* size) {
    return WGFMU_getPatternMeasureTimeSize(patternName, size);
}
int getPatternMeasureTimes(const char* patternName, int offset, int* size, double* measureTimes) {
    return WGFMU_getPatternMeasureTimes(patternName, offset, size, measureTimes);
}
int getPatternMeasureTime(const char* patternName, int index, double* measureTime) {
    return WGFMU_getPatternMeasureTime(patternName, index, measureTime);
}
int getForceValueSize(int channelId, double* size) {
    return WGFMU_getForceValueSize(channelId, size);
}
int getForceValues(int channelId, double offset, int* size, double* forceTimes, double* forceValues) {
    return WGFMU_getForceValues(channelId, offset, size, forceTimes, forceValues);
}
int getForceValue(int channelId, double index, double* forceTime, double* forceValue) {
    return WGFMU_getForceValue(channelId, index, forceTime, forceValue);
}
int getInterpolatedForceValue(int channelId, double time, double* forceValue) {
    return WGFMU_getInterpolatedForceValue(channelId, time, forceValue);
}
int getMeasureTimeSize(int channelId, int* size) {
    return WGFMU_getMeasureTimeSize(channelId, size);
}
int getMeasureTimes(int channelId, int offset, int* size, double* measureTimes) {
    return WGFMU_getMeasureTimes(channelId, offset, size, measureTimes);
}
int getMeasureTime(int channelId, int index, double* measureTime) {
    return WGFMU_getMeasureTime(channelId, index, measureTime);
}
int getMeasureEventSize(int channelId, int* size) {
    return WGFMU_getMeasureEventSize(channelId, size);
}
int getMeasureEvents(int channelId, int offset, int* size, std::vector<std::string> patternNames, std::vector<std::string> eventNames, int* cycles, double* loops, int* counts, int* offsets, int* sizes) {
    std::vector<char*> cstrs;
    for (auto& str : eventNames) {
        cstrs.push_back(const_cast<char*>(str.c_str()));
    }

    // Optional: Add a nullptr terminator if the API expects a null-terminated list
    // cstrs.push_back(nullptr);

    // Get the char** pointer
    char** d_eventNames = cstrs.data();

    std::vector<char*> cstrs2;
    for (auto& str : patternNames) {
        cstrs2.push_back(const_cast<char*>(str.c_str()));
    }

    // Optional: Add a nullptr terminator if the API expects a null-terminated list
    // cstrs.push_back(nullptr);

    // Get the char** pointer
    char** d_patternNames = cstrs2.data();
    return WGFMU_getMeasureEvents(channelId, offset, size, d_patternNames, d_eventNames, cycles, loops, counts, offsets, sizes);
}
int getMeasureEvent(int channelId, int index, char* patternName, char* eventName, int* cycle, double* loop, int* count, int* offset, int* size) {
    return WGFMU_getMeasureEvent(channelId, index, patternName, eventName, cycle, loop, count, offset, size);
}
int getMeasureEventAttribute(int channelId, int index, double* time, int* measurementPoints, double* measurementInterval, double* averagingTime, int* rawData) {
    return WGFMU_getMeasureEventAttribute(channelId, index, time, measurementPoints, measurementInterval, averagingTime, rawData);
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
int getStatus(int* status, double* elapsedTime, double* totalTime) {
    return WGFMU_getStatus(status, elapsedTime, totalTime);
}
int getChannelStatus(int channelId, int* status, double* elapsedTime, double* totalTime) {
    return WGFMU_getChannelStatus(channelId, status, elapsedTime, totalTime);
}
int waitUntilCompleted() {
    return WGFMU_waitUntilCompleted();
}
py::tuple getMeasureValueSize(int channelId) {
    int rv, measuredSize, totalSize;

    rv = WGFMU_getMeasureValueSize(channelId, &measuredSize, &totalSize);

    return py::make_tuple(rv, measuredSize, totalSize);
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
int isMeasureEventCompleted(int channelId, const char* patternName, const char* eventName, int cycle, double loop, int count, int* completed, int* index, int* offset, int* size) {
    return WGFMU_isMeasureEventCompleted(channelId, patternName, eventName, cycle, loop, count, completed, index, offset, size);
}
int dcforceVoltage(int channelId, double voltage) {
    return WGFMU_dcforceVoltage(channelId, voltage);
}
int dcmeasureValue(int channelId, double* value) {
    return WGFMU_dcmeasureValue(channelId, value);
}
int dcmeasureAveragedValue(int channelId, int count, int interval, double* value) {
    return WGFMU_dcmeasureAveragedValue(channelId, count, interval, value);
}

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
    m.def("getChannelIdSize", &getChannelIdSize, R"pbdoc(
                getChannelIdSize wgfmu
        )pbdoc");
    m.def("getChannelIds", &getChannelIds, R"pbdoc(
                getChannelIds wgfmu
        )pbdoc");
    m.def("getErrorSize", &getErrorSize, R"pbdoc(
                getErrorSize wgfmu
        )pbdoc");
    m.def("getError", &getError, R"pbdoc(
                getError wgfmu
        )pbdoc");
    m.def("getErrorSummarySize", &getErrorSummarySize, R"pbdoc(
                getErrorSummarySize wgfmu
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
    m.def("getWarningSummarySize", &getWarningSummarySize, R"pbdoc(
                getWarningSummarySize wgfmu
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
    m.def("getPatternForceValueSize", &getPatternForceValueSize, R"pbdoc(
                getPatternForceValueSize wgfmu
        )pbdoc");
    m.def("getPatternForceValues", &getPatternForceValues, R"pbdoc(
                getPatternForceValues wgfmu
        )pbdoc");
    m.def("getPatternForceValue", &getPatternForceValue, R"pbdoc(
                getPatternForceValue wgfmu
        )pbdoc");
    m.def("getPatternInterpolatedForceValue", &getPatternInterpolatedForceValue, R"pbdoc(
                getPatternInterpolatedForceValue wgfmu
        )pbdoc");
    m.def("getPatternMeasureTimeSize", &getPatternMeasureTimeSize, R"pbdoc(
                getPatternMeasureTimeSize wgfmu
        )pbdoc");
    m.def("getPatternMeasureTimes", &getPatternMeasureTimes, R"pbdoc(
                getPatternMeasureTimes wgfmu
        )pbdoc");
    m.def("getPatternMeasureTime", &getPatternMeasureTime, R"pbdoc(
                getPatternMeasureTime wgfmu
        )pbdoc");
    m.def("getForceValueSize", &getForceValueSize, R"pbdoc(
                getForceValueSize wgfmu
        )pbdoc");
    m.def("getForceValues", &getForceValues, R"pbdoc(
                getForceValues wgfmu
        )pbdoc");
    m.def("getForceValue", &getForceValue, R"pbdoc(
                getForceValue wgfmu
        )pbdoc");
    m.def("getInterpolatedForceValue", &getInterpolatedForceValue, R"pbdoc(
                getInterpolatedForceValue wgfmu
        )pbdoc");
    m.def("getMeasureTimeSize", &getMeasureTimeSize, R"pbdoc(
                getMeasureTimeSize wgfmu
        )pbdoc");
    m.def("getMeasureTimes", &getMeasureTimes, R"pbdoc(
                getMeasureTimes wgfmu
        )pbdoc");
    m.def("getMeasureTime", &getMeasureTime, R"pbdoc(
                getMeasureTime wgfmu
        )pbdoc");
    m.def("getMeasureEventSize", &getMeasureEventSize, R"pbdoc(
                getMeasureEventSize wgfmu
        )pbdoc");
    m.def("getMeasureEvents", &getMeasureEvents, R"pbdoc(
                getMeasureEvents wgfmu
        )pbdoc");
    m.def("getMeasureEvent", &getMeasureEvent, R"pbdoc(
                getMeasureEvent wgfmu
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
    
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}