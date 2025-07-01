def abort() -> int:
    """
    This function stops the sequencer of all WGFMU channels. After this command, the
    channels keep the output voltage when this command is executed.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    """
    pass

def abortChannel(channel: int) -> int:
    """
    This function stops the sequencer of the specified channel. After this command, the
    channel keeps the output voltage when this command is executed.

    parameters
    ----------
    channel : int
        The channel number to stop the sequencer for.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    """
    pass

def addSequence(channel: int, pattern: str, count: float) -> int:
    """
    This function specifies a sequence by using pattern and count, and connects it to the
    last point of the sequence data set to the specified channel.

    parameters
    ----------
    channel : int
        The channel number to add the sequence to.
    pattern : str
        The name of the waveform pattern.
    count : float
        The repeat count of the waveform pattern.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    chId = 101
    ptn = "Pattern1"
    cnt = 10
    create_pattern(ptn, 0)  # 0 ms, 0 V
    add_vector(ptn, 0.04, 0)  # 40 ms, 0 V
    add_vector(ptn, 0.01, 5)  # 50 ms, 5 V
    add_vector(ptn, 0.04, 5)  # 90 ms, 5 V
    add_vector(ptn, 0.01, 0)  # 100 ms, 0 V
    addSequence(chId, ptn, cnt)
    """
    pass

def addSequences(channel: int, patterns: list[str], counts: list[float], size: int) -> int:
    """
    This function specifies sequences by using pattern and count, and connects them to the
    last point of the sequence data set to the specified channel in the array element order.

    parameters
    ----------
    channel : int
        The channel number to add the sequences to.
    patterns : list[str]
        A list of waveform pattern names.
    counts : list[float]
        A list of repeat counts for each waveform pattern.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    chId = 101
    size = 3
    pts = ["Initial", "Pattern1", "Pattern2"]
    cts = [1, 5, 5]
    addSequences(chId, pts, cts, size)
    """
    pass

def addVector(pattern: str, dTime: float, voltage: float) -> int:
    """
    This function specifies a scalar data by using dTime and voltage, and connects it to
    the last point of the specified waveform pattern. This adds a vector to the pattern.
    
    parameters
    ----------
    pattern : str
        The name of the waveform pattern to add a vector to.
    dTime : float
        The incremental time value in seconds (10^-8 to 10995.11627775 seconds).
    voltage : float
        The output voltage in volts (within the range specified in Table 4-2).

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    ptn = "Pattern2"
    createPattern(ptn, 0)  # 0 ms, 0 V
    addVector(ptn, 0.01, 0)  # 10 ms, 0 V
    addVector(ptn, 0.01, -5)  # 20 ms, -5 V
    addVector(ptn, 0.03, -5)  # 50 ms, -5 V
    addVector(ptn, 0.01, 5)  # 60 ms, 5 V
    addVector(ptn, 0.03, 5)  # 90 ms, 5 V
    """
    pass


def addVectors(pattern: str, dTime: list[float], voltage: list[float], size: int) -> int:
    """
    This function specifies multiple scalar data by using dTime and voltage, and
    connects them to the last point of the specified waveform pattern in the array
    element order. This adds vectors to the pattern.

    parameters
    ----------
    pattern : str
        The name of the waveform pattern to add vectors to.
    dTime : list[float]
        A list of incremental time values in seconds (10^-8 to 10995.11627775 seconds).
    voltage : list[float]
        A list of output voltages in volts (within the range specified in Table 4-2).
    size : int
        The number of elements in the dTime and voltage lists.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    ptn = "Pattern2"
    dts = [0.01, 0.01, 0.03, 0.01, 0.03]  # in seconds
    vts = [0, -5, -5, 5, 5]  # in volts
    addVectors(ptn, dts, vts, len(dts))
    """
    pass

def clear() -> int:
    """
    This function clears the instrument library’s software setup information such as all
    pattern and sequence information, error, error summary, warning, warning summary,
    and warning level. It does not change the hardware status.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    """
    pass

def closeLogFile() -> int:
    """
    This function closes the log file opened by the WGFMU_openLogFile function.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    """
    pass

def closeSession() -> int:
    """
    This function closes the session (communication with B1500A) opened by the
    WGFMU_openSession function.
    
    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    """
    pass

def connect(channel: int) -> int:
    """
    This function enables the specified WGFMU channel and the RSU connected to the
    WGFMU.
    
    parameters
    ----------
    channel : int
        The channel number to connect (101 to 1002).
    
    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    """
    pass

def createMergedPattern(pattern: str, pattern1: str, pattern2: str, direction: int) -> int:
    """
    This function creates a waveform pattern by copying the waveform specified by
    pattern1 and adding the waveform specified by pattern2.

    parameters
    ----------
    pattern : str
        The name of the waveform pattern to create.
    pattern1 : str
        The name of the waveform pattern to be copied.
    pattern2 : str
        The name of the waveform pattern to be added.
    direction : int
        The direction to add the waveform pattern (WGFMU_AXIS_TIME or WGFMU_AXIS_VOLTAGE).

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    ptn = "Pattern5"
    ptn1 = "Pattern1"
    ptn2 = "Pattern2"
    createMergedPattern(ptn, ptn1, ptn2, WGFMU_AXIS_TIME)
    """
    pass

def createMultipliedPattern(pattern: str, pattern1: str, factorT: float, factorV: float) -> int:
    """
    This function creates a waveform pattern by copying the waveform specified by
    pattern1 and multiplying the waveform by the specified factor for each direction;
    time and voltage.

    parameters
    ----------
    pattern : str
        The name of the waveform pattern to create.
    pattern1 : str
        The name of the waveform pattern to be copied.
    factorT : float
        The multiplier factor in the time direction (non-zero value).
    factorV : float
        The multiplier factor in the voltage direction (non-zero value).

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    ptn = "Pattern6"
    ptn1 = "Pattern1"
    ftime = 2.0
    fvolt = 2.0
    createMultipliedPattern(ptn, ptn1, ftime, fvolt)
    """
    pass

def createOffsetPattern(pattern: str, pattern1: str, offsetT: float, offsetV: float) -> int:
    """
    This function creates a waveform pattern by copying the waveform specified by
    pattern1 and adding the specified offset for each direction; time and voltage.

    parameters
    ----------
    pattern : str
        The name of the waveform pattern to create.
    pattern1 : str
        The name of the waveform pattern to be copied.
    offsetT : float
        The offset value in the time direction, in seconds.
    offsetV : float
        The offset value in the voltage direction, in volts.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    ptn = "Pattern7"
    ptn1 = "Pattern1"
    otime = 1.0  # seconds
    ovolt = -2.0  # volts
    createOffsetPattern(ptn, ptn1, otime, ovolt)
    """
    pass

def createPattern(pattern: str, initV: float) -> int:
    """
    This function creates a waveform pattern with an initial voltage.

    parameters
    ----------
    pattern : str
        The name of the waveform pattern to create.
    initV : float
        The initial voltage value for the start point of the pattern, in volts.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    ret = createPattern("Pattern0", 0.0)  # Creates a pattern with 0 V at time 0 s.
    """
    pass

def dcforceVoltage(channel: int, voltage: float) -> int:
    """
    This function starts DC voltage output immediately by using the specified channel.

    parameters
    ----------
    channel : int
        The channel number to set the DC voltage output for (101 to 1002).
    voltage : float
        The output voltage in volts (within the range specified in Table 4-2).

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    chId = 101
    dcvol = 5.0
    dcforceVoltage(chId, dcvol)
    """
    pass

def dcmeasureAveragedValue(channel: int, points: int, interval: int) -> float:
    """
    This function starts a sampling measurement immediately by using the specified
    channel and returns the averaged measurement voltage or current.
    
    parameters
    ----------
    channel : int
        The channel number to measure (101 to 1002).
    points : int
        The number of sampling points (1 to 65535).
    interval : int
        The sampling interval in multiples of 5 ns (1 to 65535).
    
    returns
    -------
    float
        The averaged measurement value in volts or amperes.
    example
    -------
    chId = 101
    count = 5
    interval = 2
    mVal = dcmeasureAveragedValue(chId, count, interval)
    """

def dcmeasureValue(channel: int) -> float:
    """
    This function starts a voltage or current measurement immediately by using the
    specified channel and returns the measurement value.

    parameters
    ----------
    channel : int
        The channel number to measure (101 to 1002).

    returns
    -------
    float
        The measured value in volts or amperes.

    example
    -------
    chId = 101
    mVal = dcmeasureValue(chId)
    """
    pass

def disconnect(channel: int) -> int:
    """
    This function disables the specified WGFMU channel and the RSU.
    
    parameters
    ----------
    channel : int
        The channel number to disconnect (101 to 1002).
    
    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    """
    pass

def doSelfCalibration() -> tuple[int, str]:
    """
    This function performs the self-calibration for the mainframe and all modules.
    It returns the self-calibration result and a detail string.
    
    returns
    -------
    tuple[int, str]
        A tuple containing the self-calibration result (int) and a detail string (str).
        The result can be:
        - 0: Mainframe and all modules passed self-calibration.
        - 2N-1: Slot N module failed self-calibration.
        - 210 (1024): Mainframe failed self-calibration.

    """
    pass

def doSelfTest() -> tuple[int, str]:
    """
    This function performs the self-test for the mainframe and all modules.
    It returns the self-test result and a detail string.
    
    returns
    -------
    tuple[int, str]
        A tuple containing the self-test result (int) and a detail string (str).
        The result can be:
        - 0: Mainframe and all modules passed self-test.
        - 2N-1: Slot N module failed self-test.
        - 210 (1024): Mainframe failed self-test.
    """
    pass

def execute() -> int:
    """
    This function runs the sequencer of all enabled WGFMU channels in the Fast IV
    mode or the PG mode. The channels start the predefined operation. If there are
    channels in the run status, this function stops the sequencers and runs the sequencer
    of all enabled WGFMU channels. After the execution, the channels keep the last
    output voltage.
    It applies the setup of the following functions to the channel:
    - WGFMU_setOperationMode
    - WGFMU_setForceVoltageRange
    - WGFMU_setMeasureCurrentRange
    - WGFMU_setMeasureVoltageRange
    - WGFMU_setMeasureMode

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    """
    pass

def exportAscii(file: str) -> int:
    """
    This function creates a setup summary report and saves it as a CSV (comma separated
    values) file. The summary report contains the pattern data, event data, and sequence
    data for the channels configured by the instrument library. The file can be read by
    using a spreadsheet software. This is effective for quick debugging. If the specified
    file does not exist, this function creates a new file. If the specified file exists,
    this function overwrites the file. An error occurs if an invalid path is specified, a
    file is not created, or a setup summary is not written.
    
    parameters
    ----------
    file : str
        The name of the summary report file. The file extension will be .csv if you
        do not specify it.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    ret = exportAscii("C:/Keysight/B1530A/setup/summary1.csv")
    """
    pass

def getChannelIds() -> list[int]:
    """
    This function retrieves the channel IDs of the WGFMU channels installed in the B1500A
    connected to this session.

    returns
    -------
    list[int]
        A list of WGFMU channel IDs.
    """
    pass

def getChannelStatus(channel: int) -> tuple[int, float, float]:
    """
    This function retrieves the status of the specified channel in the Fast IV mode or the
    PG mode, along with the estimated elapsed time and total time until all sequences are
    completed.

    parameters
    ----------
    channel : int
        The channel number to get the status for (101 to 1002).
    
    returns
    -------
    tuple[int, float, float]
        A tuple containing:
        - int: The status of the channel (see Table 4-17 for possible values).
        - float: The estimated elapsed time in seconds.
        - float: The estimated total time until all sequences are completed in seconds.
    """
    pass

def getError() -> str:
    """
    This function retrieves one error string from the WGFMU library. To know the length of
    the next error string, you can use the `getErrorSize` function. The error
    string is cleared by the `clear` function.
    
    returns
    -------
    str
        The error string retrieved from the WGFMU library. If no error, returns an empty
        string.
    """
    pass

def getErrorSummary() -> str:
    """
    This function retrieves the error summary string which contains all errors. To know the
    length of the error summary string, you can use the `getErrorSummarySize` function
    The error summary string is cleared by the `clear` function.
    
    returns
    -------
    str
        The error summary string retrieved from the WGFMU library. If no errors, returns
        an empty string.
    """
    pass

def getForceDelay(channel: int) -> float:
    """
    This function returns the device delay time of the specified source channel in the
    Fast IV mode or the PG mode.

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).

    returns
    -------
    float
        The device delay time in seconds, which must be between -50 ns and 50 ns,
        in 625 ps resolution.
    
    example
    -------
    chId = 101
    delay = getForceDelay(chId)
    """
    pass


def getForceValues(channel: int, index: int) -> tuple[list[float], list[float]]:
    """
    This function specifies a channel and a range of sequence data, and returns the
    corresponding setup data (time and voltage). To know the total number of setup
    data, execute the `getForceValueSize` function.
    
    parameters
    ----------
    channel : int
        The channel number (101 to 1002).
    index : int
        The first index of the sequence data to read setup (0 to total number of setup data - 1).

    returns
    -------
    tuple[list[float], list[float]]
        A tuple containing:
        - list[float]: A list of time data in seconds.
        - list[float]: A list of voltage data in volts.
    """
    pass

def getForceVoltageRange(channel: int) -> int:
    """
    This function returns the voltage output range set to the specified channel.
    The value is set by the `setForceVoltageRange` function. The setting is applied
    to the channel by the `update`, `updateChannel`, `execute`, or the functions of
    the DC measurement group.

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).

    returns
    -------
    int
        The voltage output range, which can be one of the predefined constants.
    
    example
    -------
    chId = 101
    fRange = getForceVoltageRange(chId)
    """
    pass

def getInterpolatedForceValue(channel: int, time: float) -> float:
    """
    This function specifies a channel and a time value, and returns the voltage
    value applied by the specified WGFMU channel at the specified time. The returned
    value may be the value given by the interpolation.

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).
    time : float
        The time to read the voltage output value, in seconds (0 to length of the waveform).

    returns
    -------
    float
        The voltage output value in volts at the specified time.
    
    example
    -------
    chId = 101
    reTm = 1E-6  # 1 microsecond
    volt = getInterpolatedForceValue(chId, reTm)
    """
    pass

def getMeasureCurrentRange(channel: int) -> int:
    """
    This function returns the current measurement range set to the specified channel.
    The value is set by the `setMeasureCurrentRange` function. The setting is applied
    to the channel by the `update`, `updateChannel`, `execute`, or the functions of
    the DC measurement group. The setting is not effective for the voltage measurement mode.
    
    parameters
    ----------
    channel : int
        The channel number (101 to 1002).
        
    returns
    -------
    int
        The current measurement range, which can be one of the predefined constants.
    """
    pass

def getMeasureDelay(channel: int) -> float:
    """
    This function returns the device delay time of the specified measurement channel in
    the Fast IV mode or the PG mode.
    
    parameters
    ----------
    channel : int
        The channel number (101 to 1002).
        
    returns
    -------
    float
        The device delay time in seconds, which must be between -50 ns and 50 ns,
        in 625 ps resolution. If the value is not a multiple number of 625 ps, it is rounded
        to the nearest multiple number.

    example
    -------
    chId = 101
    delay = getMeasureDelay(chId)  # Returns the device delay time for channel 101.
    """
    pass

def getMeasureEvents(channel: int, measId: int) -> tuple[list[str], list[str], list[int], list[float], list[int], list[int], list[int]]:
    """
    This function specifies a channel and a range of measurement events, and returns the
    corresponding setup (pattern, event, cycle, loop, count, index, and length).
    
    parameters
    ----------
    channel : int
        The channel number (101 to 1002).
    measId : int
        The first index of the measurement events to read setup. measId must be
        0 to the total number of measurement events - 1. Error occurs if the value is out of this range.

    returns
    -------
    tuple[list[str], list[str], list[int], list[float], list[int], list[int], list[int]]
        A tuple containing:
        - list[str]: A list of waveform pattern names.
        - list[str]: A list of event names.
        - list[int]: A list of usage counts (how many times the pattern is used in the sequence).
        - list[float]: A list of loop counts (how many times the pattern is looped).
        - list[int]: A list of event counts (how many times the event is used in the pattern).
        - list[int]: A list of first data indices assigned to the specified measurement event.
        - list[int]: A list of number of sampling points for the specified measurement event.
    """
    pass

def getMeasureEventAttribute(channel: int, measId: int) -> tuple[float, int, float, float, int]:
    """
    This function specifies a channel and a measurement event index, and returns the
    corresponding measurement event attribute (time, points, interval, average, and rdata)

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).
    measId : int
        Measurement event index. For instance, the index can be read by
        `isMeasureEventCompleted`.

    returns
    -------
    tuple[float, int, float, float, int]
        A tuple containing:
        - float: The measurement start time in the pattern, in seconds.
        - int: The number of sampling points.
        - float: The sampling interval, in seconds.
        - float: The averaging time, in seconds.
        - int: The rdata value of `setMeasureEvent`.
    """
    pass

def getMeasureMode(channel: int) -> int:
    """
    This function returns the measurement mode set to the specified channel. The value
    is set by the `setMeasureMode` function. The setting is applied to the channel by
    the `update`, `updateChannel`, `execute`, or the functions of the DC measurement group.

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).

    returns
    -------
    int
        The measurement mode, which can be one of the predefined constants.
    
    example
    -------
    chId = 101
    mMode = getMeasureMode(chId)
    """
    pass

def getMeasureTimes(channel: int, index: int, length: int) -> tuple[list[float], int]:
    """
    This function specifies a channel and a range of measurement points, and returns the
    measurement start time for the points. To know the total number of measurement points,
    execute the `getMeasureTimeSize` function.

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).
    index : int
        The first index of the measurement points to read the measurement start time.
    length : int
        The number of measurement points to read the measurement start time.

    returns
    -------
    tuple[list[float], int]
        A tuple containing:
        - list[float]: A list of measurement start times in seconds.
        - int: The actual number of measurement times returned.
    
    example
    -------
    chId = 101
    idx = 0
    len = 5
    mTimes, actualLen = getMeasureTimes(chId, idx, len)
    """
    pass

def getMeasureValues(channel: int, index: int) -> tuple[list[float], list[float]]:
    """
    This function specifies a channel and an index of measurement points, and returns the
    measurement data (time and value) for the points. For the averaging measurement which
    takes multiple data for one point measurement, the returned value is the value given by
    averaging the multiple measured values.

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).
    index : int
        The index of the measurement point to read the measured value.
        The index must be 0 to the total number of measurement points - 1.

    returns
    -------
    tuple[list[float], list[float], int]
        A tuple containing:
        - list[float]: A list of measurement start times in seconds.
        - list[float]: A list of measured values in volts or amperes.
    
    example
    -------
    chId = 101
    idx = 0
    mTimes, mValues = getMeasureValues(chId, idx)
    """
    pass

def getMeasureVoltageRange(channel: int) -> int:
    """
    This function returns the voltage measurement range set to the specified channel.
    The value is set by the `setMeasureVoltageRange` function. The setting is applied
    to the channel by the `update`, `updateChannel`, `execute`, or the functions of
    the DC measurement group. The setting is not effective for the current measurement mode.

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).

    returns
    -------
    int
        The voltage measurement range, which can be one of the predefined constants.
    
    example
    -------
    chId = 101
    mRange = getMeasureVoltageRange(chId)
    """
    pass

def getOperationMode(channel: int) -> int:
    """
    This function returns the operation mode set to the specified channel. The value is
    set by the `setOperationMode` function. The setting is applied to the channel by
    the `update`, `updateChannel`, `execute`, or the functions of the DC measurement group.

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).

    returns
    -------
    int
        The operation mode, which can be one of the predefined constants.
    
    example
    -------
    chId = 101
    omode = getOperationMode(chId)
    """
    pass

def getPatternForceValues(channel: int, index: int) -> tuple[list[float], list[float]]:
    """
    This function specifies a channel and an index of scalar, and returns the
    corresponding scalar data (time and voltage).

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).
    index : int
        The index of the scalar to read data. The index must be 0 to the total number of
        scalar - 1. Error occurs if the value is out of this range.

    returns
    -------
    tuple[list[float], list[float]]
        A tuple containing:
        - list[float]: A list of time data in seconds.
        - list[float]: A list of voltage data in volts.
    
    example
    -------
    chId = 101
    idx = 0
    times, voltages = getPatternForceValues(chId, idx)
    """
    pass

def getPatternInterpolatedForceValue(channel: int, time: float) -> float:
    """
    This function specifies a channel and a time value, and returns the voltage
    value applied by the specified WGFMU channel at the specified time. The returned
    value may be the value given by the interpolation.

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).
    time : float
        The time to read the voltage output value, in seconds (0 to length of the waveform).

    returns
    -------
    float
        The voltage output value in volts at the specified time.
    
    example
    -------
    chId = 101
    reTm = 1E-6  # 1 microsecond
    volt = getPatternInterpolatedForceValue(chId, reTm)
    """
    pass

def getPatternMeasureTimes(channel: int) -> tuple[list[float], int]:
    """
    This function specifies a channel and a range of measurement points, and returns the
    measurement start time for the points. For the averaging measurement which takes
    multiple data for one point measurement, the returned value will be (start time +
    stop time)/2.

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).

    returns
    -------
    tuple[list[float], int]
        A tuple containing:
        - list[float]: A list of measurement start times in seconds.
    
    example
    -------
    chId = 101
    idx = 0
    len = 5
    mTimes = getPatternMeasureTimes(chId)
    """
    pass

def getStatus() -> tuple[int, float, float]:
    """
    This function reads the status of the WGFMU channels in the Fast IV mode or the
    PG mode. The returned values are the maximum of the values presented by all
    active channels.

    returns
    -------
    tuple[int, float, float]
        A tuple containing:
        - int: The status of the WGFMU channels (see Table 4-17 for possible values).
        - float: The estimated elapsed time in seconds.
        - float: The estimated total time until all sequences are completed in seconds.
    """
    pass
    
def getTriggerOutMode(channel: int) -> tuple[int, int]:
    """
    This function returns the trigger output mode and polarity of the specified channel.

    parameters
    ----------
    channel : int
        The channel number (101 to 1002).

    returns
    -------
    tuple[int, int]
        A tuple containing:
        - int: The trigger output mode (see Table 4-11 for possible values).
        - int: The trigger polarity (see Table 4-11 for possible values).
    
    example
    -------
    chId = 101
    tMode, tPol = getTriggerOutMode(chId)
    """
    pass

def getWarningLevel() -> int:
    """
    This function reads the warning level setting. The warning level affects the
    behavior of the WGFMU_getWarningSummary, WGFMU_getWarningSummarySize, and
    WGFMU_openLogFile functions.

    returns
    -------
    int
        The warning level setting (see Table 4-4 for possible values).
    """
    pass
    
def getWarningSummary() -> str:
    """
    This function reads the warning summary string which contains all warnings.
    The warning summary string is cleared by the `clear` function.

    returns
    -------
    str
        The warning summary string retrieved from the WGFMU library. If no warnings,
        returns an empty string.
    """
    pass

def initialize() -> int:
    """
    This function resets all WGFMU channels. It does not clear the software setup
    information of the instrument library.
    
    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    """
    pass

def isMeasureEnabled(channel: int) -> int:
    """
    This function checks if the specified channel is enabled or disabled for measurement.
    This function is not available for the channels in the DC mode.

    parameters
    ----------
    channel : int
        The channel number to check (101 to 1002).
    
    returns
    -------
    int
        The measurement status of the channel, where:
        - 7000 (WGFMU_MEASURE_ENABLED_DISABLE): The channel cannot perform measurement.
        - 7001 (WGFMU_MEASURE_ENABLED_ENABLE): The channel can perform measurement.
    """
    pass

def isMeasureEventCompleted(channel: int, pattern: str, event: str, cycle: int, loop: float, count: int) -> tuple[int, int, int, int]:
    """
    This function checks if a specified measurement event is completed and returns its
    execution status, measurement event index, first data index, and number of sampling points.
    
    parameters
    ----------
    channel : int
        The channel number to check (101 to 1002).
    pattern : str
        The name of the waveform pattern to get the event address.
    event : str
        The name of the event to get the event address.
    cycle : int
        The usage count, starting from 0. This parameter indicates how many times the
        specified pattern is used in the sequence of the specified channel.
    loop : float
        The loop count, starting from 0. This parameter indicates how many times the    
        specified pattern is looped in the sequence of the specified channel.
    count : int
        The event count, starting from 0. This parameter indicates how many times the   
        specified event is used in the specified pattern.
    
    returns
    -------
    tuple[int, int, int, int]
        A tuple containing:
        - int: The execution status of the specified measurement event (see Table 4-13 for possible values).
        - int: The measurement event index used for `getMeasureEventAttribute`.
        - int: The first data index assigned to the specified measurement event.
        - int: The number of sampling points for the specified measurement event.
    """
    pass

def openLogFile(file: str) -> int:
    """
    This function opens a file used to log errors and warnings. If the specified file does
    not exist, this function creates a new file. If the specified file exists, this function
    appends the log information to the file. An error occurs if an invalid path is specified,
    a file is not created, or a log information is not written.

    parameters
    ----------
    file : str
        The name of the log file to store errors and warnings information.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    ret = openLogFile("C:/Keysight/B1530A/log/20080901.log")
    """
    pass

def openSession(address: str) -> int:
    """
    This function opens the communication session with the B1500A by using the WGFMU
    instrument library.
    
    parameters
    ----------
    address : str
        The VISA address of the B1500A instrument (e.g., "GPIB0::17::INSTR").
    
    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    ret = openSession("GPIB0::17::INSTR")
    """
    pass

def setForceDelay(channel: int, delay: float) -> int:
    """
    This function sets the device delay time of the specified source channel in the Fast
    IV mode or the PG mode.

    parameters
    ----------
    channel : int
        The channel number to set the delay for (101 to 1002).
    delay : float
        The device delay time in seconds, which must be between -50 ns and 50 ns,
        in 625 ps resolution. If the value is not a multiple number of 625 ps, it is rounded
        to the nearest multiple number.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    ret = setForceDelay(101, 1E-8)  # Set delay for channel 101 to 10 microseconds.
    """
    pass

def setForceVoltageRange(channel: int, range: int) -> int:
    """
    This function sets the voltage output range of the specified source channel. The
    setting is applied to the channel by the `update`, `updateChannel`, `execute`, or
    the functions of the DC measurement group.

    parameters
    ----------
    channel : int
        The channel number to set the voltage range for (101 to 1002).
    range : int
        The voltage output range, which can be one of the predefined constants.
    
    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    ret = setForceVoltageRange(101, WGFMU_FORCE_VOLTAGE_RANGE_10V_POSITIVE)
    """
    pass

def setMeasureCurrentRange(channel: int, range: int) -> int:
    """
    This function sets the current measurement range of the specified measurement channel.
    The setting is applied to the channel by the `update`, `updateChannel`, `execute`, or
    the functions of the DC measurement group. The setting is not effective for the voltage
    measurement mode.

    parameters
    ----------
    channel : int
        The channel number to set the current range for (101 to 1002).
    range : int
        The current measurement range, which can be one of the predefined constants.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    ret = setMeasureCurrentRange(101, WGFMU_MEASURE_CURRENT_RANGE_1MA)
    """
    pass

def setMeasureDelay(channel: int, delay: float) -> int:
    """
    This function sets the device delay time of the specified measurement channel in the
    Fast IV mode or the PG mode.

    parameters
    ----------
    channel : int
        The channel number to set the delay for (101 to 1002).
    delay : float
        The device delay time in seconds, which must be between -50 ns and 50 ns,
        in 625 ps resolution. If the value is not a multiple number of 625 ps, it is rounded
        to the nearest multiple number.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    ret = setMeasureDelay(101, -1E-8)  # Set delay for channel 101 to -10 microseconds.
    """
    pass

def setMeasureEnabled(channel: int, status: int) -> int:
    """
    This function enables or disables the measurement ability of the specified channel.
    This function is not available for the channels in the DC mode.

    parameters
    ----------
    channel : int
        The channel number to set the measurement status for (101 to 1002).
    status : int
        The measurement status to set, which can be one of the predefined constants.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    chId = 101
    ret = setMeasureEnabled(chId, WGFMU_MEASURE_ENABLED_ENABLE)
    """
    pass

def setMeasureEvent(pattern: str, event: str, time: float, points: int, interval: float, average: float, rdata: MEASURE_EVENT_DATA_OUTPUT_MODE) -> int:
    """
    This function defines a measurement event which is a sampling measurement
    performed by the WGFMU channel while it outputs a waveform pattern. The waveform
    pattern specified by `pattern` must be created before this function is executed.

    parameters
    ----------
    pattern : str
        The name of the waveform pattern to get the event address.
    event : str
        The name of the event to get the event address.
    time : float
        The measurement start time, in seconds. Sampling measurement is started at this time.
    points : int
        The number of sampling points. Must be a positive integer.
    interval : float
        The sampling interval, in seconds. Must be between 10 ns and 1.34217728 seconds.
    average : float
        The averaging time, in seconds. Must be 0 (no averaging) or between 10 ns and 20 ms.
    rdata : MEASURE_EVENT_DATA_OUTPUT_MODE
        The output mode of the measurement event data, which can be one of the predefined constants:
        AVERAGED or RAW

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    ret = setMeasureEvent("Pattern1", "ev1", 0.001, 5, 0.0001, 0, WGFMU_MEASURE_EVENT_DATA_RAW)
    """
    pass

def setMeasureMode(channel: int, mode: MEASURE_MODE) -> int:
    """
    This function sets the measurement mode of the specified channel. The setting is
    applied to the channel by the `update`, `updateChannel`, `execute`, or the functions
    of the DC measurement group.

    parameters
    ----------
    channel : int
        The channel number to set the measurement mode for (101 to 1002).
    mode : MEASURE_MODE
        The measurement mode to set, which can be one of the predefined constants:  
        VOLTAGE, CURRENT

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    chId = 101
    ret = setMeasureMode(chId, WGFMU_MEASURE_MODE_VOLTAGE)
    """
    pass

def setMeasureVoltageRange(channel: int, range: int) -> int:
    """
    This function sets the voltage measurement range of the specified measurement channel.
    The setting is applied to the channel by the `update`, `updateChannel`, `execute`, or
    the functions of the DC measurement group. The setting is not effective for the current
    measurement mode.

    parameters
    ----------
    channel : int
        The channel number to set the voltage range for (101 to 1002).
    range : int
        The voltage measurement range to set, which can be one of the predefined constants.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    chId = 101
    ret = setMeasureVoltageRange(chId, WGFMU_MEASURE_VOLTAGE_RANGE_10V)
    """
    pass

def setOperationMode(channel: int, mode: OPERATION_MODE) -> int:
    """
    This function sets the operation mode of the specified channel. The setting is applied
    to the channel by the `update`, `updateChannel`, `execute`, or the functions of the DC
    measurement group.

    parameters
    ----------
    channel : int
        The channel number to set the operation mode for (101 to 1002).
    mode : OPERATION_MODE
        The operation mode to set, which can be one of the predefined constants:
        DC, FASTIV, PG, or SMU.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    chId = 101
    ret = setOperationMode(chId, WGFMU_OPERATION_MODE_FASTIV)
    """
    pass

def setRangeEvent(pattern: str, event: str, time: float, range: int) -> int:
    """
    This function defines a range event which is the range change operation for the
    current measurement performed by the WGFMU channel while it outputs a waveform pattern.
    This function is available only for the current measurements in the Fast IV mode.
    The waveform pattern specified by `pattern` must be created before this function is executed.

    parameters
    ----------
    pattern : str
        The name of the waveform pattern to get the event address.
    event : str
        The name of the range event to get the event address.
    time : float
        The range change time, in seconds. Range change is performed at this time.
    range : int
        The current measurement range to set, which can be one of the predefined constants.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    ret = setRangeEvent("Pattern1", "ev1", 0.001, WGFMU_MEASURE_CURRENT_RANGE_100UA)
    """
    pass


def setTimeout(timeout: float) -> int:
    """
    This function sets the timeout for the WGFMU library operations. The timeout is
    the maximum time the library will wait for a response from the instrument before
    returning an error.
    
    parameters
    ----------
    timeout : float
        The timeout value in seconds. Must be 1 or more, with a resolution of 1 microsecond.
        If the value is less than 1, an error occurs. Default value is 100 seconds.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    """
    pass

def setTriggerOutEvent(pattern: str, event: str, time: float, duration: float) -> int:
    """
    This function defines a trigger output event which is the trigger output operation
    performed by the WGFMU channel while it outputs a waveform pattern. The waveform
    pattern specified by `pattern` must be created before this function is executed.
    
    parameters
    ----------
    pattern : str
        The name of the waveform pattern to get the event address.
    event : str
        The name of the trigger output event to get the event address.
    time : float
        The trigger output time, in seconds. Trigger is output at this time.
        Time origin is the origin of the specified pattern. Must be 0 to the total time of
        pattern in 10 ns resolution. If the value is not a multiple number of 10 ns, it is
        rounded to the nearest multiple number.
    duration : float
        The duration time of the output trigger, in seconds. If `time` and `duration` are
        both 0, the channel outputs the trigger when it starts to apply the initial voltage
        of the specified pattern.

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    ret = setTriggerOutEvent("Pattern1", "ev1", 0.001, 1E-8)  # Set trigger at 1 ms for 10 microseconds.
    """
    pass

def setVector(pattern: str, time: float, voltage: float) -> int:
    """
    This function specifies a scalar data by using time and voltage, and adds it to the
    specified waveform pattern or replaces the scalar previously defined in the specified
    waveform pattern with the scalar specified by this function. The latest execution is
    always effective. The waveform pattern specified by `pattern` must be created before
    this function is executed.

    parameters
    ----------
    pattern : str
        The name of the waveform pattern to add or replace a vector.
    time : float
        The absolute time value, not incremental time value, in seconds. Must be 0 or greater,
        in 10 ns resolution. If the specified value does not satisfy this requirement, the
        vector is not added or replaced.
    voltage : float
        The output voltage in volts. Must be within the range specified by the WGFMU
        library (e.g., -10 V to +10 V).

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    example
    -------
    ret = setVector("Pattern1", 0.01, 0)  # Set vector at 10 ms with 0 V.
    """
    pass

def setVectors(pattern: str, time: list[float], voltage: list[float]) -> int:
    """
    This function specifies multiple scalar data by using time and voltage, and adds them
    to the specified waveform pattern or replaces the scalars previously defined in the
    specified waveform pattern with the scalars specified by this function. The latest
    execution is always effective. The waveform pattern specified by `pattern` must be
    created before this function is executed.
    
    parameters
    ----------
    pattern : str
        The name of the waveform pattern to add or replace vectors.
    time : list[float]
        A list of absolute time values, not incremental time values, in seconds. Each value
        must be 0 or greater, in 10 ns resolution. If any specified value does not satisfy
        this requirement, the vectors are not added or replaced.
    voltage : list[float]
        A list of output voltages in volts. Each value must be within the range specified
        by the WGFMU library (e.g., -10 V to +10 V).

    returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    example
    -------
    ret = setVectors("Pattern1", [0.1, 0.2, 0.3, 0.4], [0, 5, 5, 0])
    """
    pass

def setWarningLevel(level: int) -> int:
    """
    This function sets the warning level. The warning level affects the behavior of the
    WGFMU_getWarningSummary, WGFMU_getWarningSummarySize, and
    WGFMU_openLogFile functions.
    
    Parameters
    ----------
    level : int
        The warning level to set, which can be one of the predefined constants.
    
    Returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    
    Example
    -------
    ret = setWarningLevel(WGFMU_WARNING_LEVEL_INFORMATION)
    """
    pass

def treatWarningsAsErrors(level: int) -> int:
    """
    This function sets the threshold between warning and error by specifying the
    warning level. If the specified level is set, all warnings of that level and above
    will be treated as errors.

    Parameters
    ----------
    level : int
        The warning level which will be the threshold between warning and error.
    
    Returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    """
    pass

def update() -> int:
    """
    This function updates the setting of all WGFMU channels in the Fast IV mode or the
    PG mode. After this function, all WGFMU channels apply the initial voltage set by
    the WGFMU_createPattern function. This function applies the setup of the following
    functions to the channels:
    - WGFMU_setOperationMode
    - WGFMU_setForceVoltageRange
    - WGFMU_setMeasureCurrentRange
    - WGFMU_setMeasureVoltageRange
    - WGFMU_setMeasureMode
    
    Returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    """
    pass

def updateChannel(channel: int) -> int:
    """
    This function updates the setting of the specified channel in the Fast IV mode or the
    PG mode. After this function, the channel applies the initial voltage set by the
    WGFMU_createPattern function. This function applies the setup of the following
    functions to the channel:
    - WGFMU_setOperationMode
    - WGFMU_setForceVoltageRange
    - WGFMU_setMeasureCurrentRange
    - WGFMU_setMeasureVoltageRange
    - WGFMU_setMeasureMode
    
    Parameters
    ----------
    channel : int
        The channel number to update (101 to 1002).

    Returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.

    """
    pass

def waitUntilCompleted() -> int:
    """
    This function waits until all connected WGFMU channels in the Fast IV mode or the
    PG mode are in the ready to read data status. An error occurs if a sequencer
    is not running or if no channel is in the Fast IV mode or the PG mode.
    
    Returns
    -------
    int
        The error code returned by the WGFMU library, where 0 indicates success.
    """
    pass


WGFMU_NO_ERROR: int
"""
No error code returned by the WGFMU library, indicating that the last operation was successful.
"""
WGFMU_PARAMETER_OUT_OF_RANGE_ERROR: int
"""
Invalid parameter value was found. It will be out of the range. Set the effective parameter value.
"""
WGFMU_ILLEGAL_STRING_ERROR: int
"""
Invalid string value was found. It will be empty or illegal (pointer). Set the effective string value.
"""
WGFMU_CONTEXT_ERROR: int
"""
Context error was found between relative functions. Set the effective parameter value.
"""
WGFMU_FUNCTION_NOT_SUPPORTED_ERROR: int
"""
Specified function is not supported by this channel. Set the channel id properly.
"""
WGFMU_COMMUNICATION_ERROR: int
"""
IO library error was found. This indicates a communication issue with the instrument.
"""
WGFMU_FW_ERROR: int
"""
Firmware error was found. This indicates an issue with the firmware of the instrument.
"""
WGFMU_LIBRARY_ERROR: int
"""
WGFMU instrument library error was found. This indicates an issue with the WGFMU library itself.
"""
WGFMU_ERROR: int
"""
Unidentified error was found. This is a general error code for unexpected issues.
"""
WGFMU_CHANNEL_NOT_FOUND_ERROR: int
"""
Specified channel id is not available for WGFMU. Set the channel id properly.
"""
WGFMU_PATTERN_NOT_FOUND_ERROR: int
"""
Unexpected pattern name was specified. Specify the effective pattern name. Or create a new pattern.
"""
WGFMU_EVENT_NOT_FOUND_ERROR: int
"""
Unexpected event name was specified. Specify the effective event name.
"""
WGFMU_PATTERN_ALREADY_EXISTS_ERROR: int
"""
Duplicate pattern name was specified. Specify the unique pattern name.
"""
WGFMU_SEQUENCER_NOT_RUNNING_ERROR: int
"""
sequencer must be run to execute the specified function. Run the sequencer.
"""
WGFMU_RESULT_NOT_READY_ERROR: int
"""
Measurement is in progress. Read the result data after the measurement is completed.
"""
WGFMU_RESULT_OUT_OF_DATE_ERROR: int
"""
Measurement result data was deleted by the setup change. The result data must be read before changing the waveform setup or the measurement setup.
"""


WGFMU_WARNING_LEVEL_OFF: int
"""
No warning is reported. Default setting for WGFMU_treatWarningsAsErrors.
"""
WGFMU_WARNING_LEVEL_SEVERE: int
"""
Reports severe warning as follows:
- When an event is tried to set on a pattern, if the event overlaps same type of events, the event overwrites the original events.
- Channel specific WGFMU - Measurement API except for update is called to a non ALWG channel.
"""
WGFMU_WARNING_LEVEL_NORMAL: int
"""
Reports normal warning as follows:
- WGFMU - Measurement API except for update is called when there is no ALWG channel.
- Not all information is stored in an array because the given “size” is less than the required size.
- All available information is stored in an array but the array is not fully filled because the given “offset + size” is greater than the total size.
- The error queue on the instrument is not empty when opening or closing a session.
"""
WGFMU_WARNING_LEVEL_INFORMATION: int
"""
Reports information warning:
- A value is rounded.
"""
from enum import Enum
class OPERATION_MODE(Enum):
    """
    Operation modes for the WGFMU channels.
    """
    DC : int
    """
    DC mode. DC voltage output and voltage or current measurement (VFVM or VFIM).
    The functions of the following group are available in this mode only:
    - DC - Measurement
    """
    FASTIV : int
    """
    Fast IV mode. ALWG voltage output and voltage or current measurement (VFVM or VFIM).
    """
    PG : int
    """PG mode. ALWG voltage output and voltage measurement (VFVM). The output voltage will be divided
    by the internal 50 Ω resistor and the load impedance. Faster than the Fast IV mode.
    """
    SMU : int
    """
    SMU mode, default setting.
    For using SMU connected to the RSU. The functions of the following groups are not available:
    - Common - Measurement
    - WGFMU - Measurement
    - WGFMU - Data retrieve
    - DC - Measurement
    """

class FORCE_VOLTAGE_RANGE(Enum):
    """
    Voltage output ranges for the WGFMU channels.
    """
    AUTO: int
    """
    Auto range, default setting.
    """
    _3V: int
    """
    3 V fixed range (-3 V to +3 V).
    """
    _5V: int
    """
    5 V fixed range (-5 V to +5 V).
    """
    _10V_NEGATIVE: int
    """
    -10 V fixed range (-10 V to 0 V).
    """
    _10V_POSITIVE: int
    """
    +10 V fixed range (0 V to +10 V).
    """

class MEASURE_MODE(Enum):
    """
    Measurement modes for the WGFMU channels.
    """
    VOLTAGE: int
    """
    Voltage measurement mode, default setting.
    Changing the mode to this mode does not change the current measurement range setting.
    """
    CURRENT: int
    """
    Current measurement mode.
    Changing the mode to this mode changes the voltage measurement range to the 5 V range.
    """

WGFMU_MEASURE_VOLTAGE_RANGE_5V: int
"""
5 V fixed range (±5 V).
"""
WGFMU_MEASURE_VOLTAGE_RANGE_10V: int
"""
10 V fixed range (±10 V), default setting.
"""
WGFMU_MEASURE_CURRENT_RANGE_1UA: int
"""
1 µA controlled range (±1 µA).
"""
WGFMU_MEASURE_CURRENT_RANGE_10UA: int
"""
10 µA controlled range (±10 µA).
"""
WGFMU_MEASURE_CURRENT_RANGE_100UA: int
"""
100 µA controlled range (±100 µA).
"""
WGFMU_MEASURE_CURRENT_RANGE_1MA: int
"""
1 mA controlled range (±1 mA).
"""
WGFMU_MEASURE_CURRENT_RANGE_10MA: int
"""
10 mA controlled range (±10 mA), default setting.
"""
WGFMU_MEASURE_ENABLED_DISABLE: int
"""
Measurement cannot be performed.
"""
WGFMU_MEASURE_ENABLED_ENABLE: int
"""
Measurement can be performed.
Default setting.
"""
WGFMU_TRIGGER_OUT_MODE_DISABLE: int
"""
No trigger output, default setting.
Disables trigger output function.
"""
WGFMU_TRIGGER_OUT_MODE_START_EXECUTION: int
"""
Execution trigger output mode.
Channel outputs trigger only when starting the first sequence output.
"""
WGFMU_TRIGGER_OUT_MODE_START_SEQUENCE: int
"""
Sequence trigger output mode.
Channel outputs trigger every start of the sequence output.
"""
WGFMU_TRIGGER_OUT_MODE_START_PATTERN: int
"""
Pattern trigger output mode.
Channel outputs trigger every start of the pattern output.
"""
WGFMU_TRIGGER_OUT_MODE_EVENT: int
"""
Event trigger output mode which enables the trigger output event.
Channel outputs trigger at the timing set by WGFMU_setTriggerOutEvent.
"""
WGFMU_TRIGGER_OUT_POLARITY_POSITIVE: int
"""
Polarity: positive, default setting.
Channel usually outputs TTL low level and outputs TTL high level at the trigger timing.
"""
WGFMU_TRIGGER_OUT_POLARITY_NEGATIVE: int
"""
Polarity: negative.
Channel usually outputs TTL high level and outputs TTL low level at the trigger timing.
"""
WGFMU_AXIS_TIME: int
"""
Time direction. The created pattern will be pattern1 plus pattern2 in this order (in the time direction). The pattern1 last point will be connected to the pattern2 second point. This deletes the pattern2 first point defined by the WGFMU_createPattern function.
"""
WGFMU_AXIS_VOLTAGE: int
"""
Voltage direction. The created pattern will be pattern1 plus pattern2 in the voltage direction. This is made by adding voltage values together during the period of the longer pattern. For the period over the shorter pattern, the last value of the shorter pattern is used for calculation.
"""
WGFMU_MEASURE_EVENT_NOT_COMPLETED: int
"""
Not completed.
"""
WGFMU_MEASURE_EVENT_COMPLETED: int
"""
Completed. Ready to read result.
"""

class MEASURE_EVENT_DATA_OUTPUT_MODE(Enum):
    """
    Measurement event data output modes for the WGFMU channels.
    """
    AVERAGED: int
    """
    Averaging data output mode. Only the averaging result data will be returned and the number of returned data will be points.
    """
    RAW: int
    """
    Raw data output mode. All of the measurement data used for averaging will be returned and the number of returned data will be points × (1 + int(average/(5 × 10^-9))).
    """