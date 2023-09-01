#ifdef TEST

#include "unity.h"
#include "mock_i2c.h"
#include "tempSensor.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_MaxValue(void){ // Testing the max value registered
    uint8_t tempRegisterAddress = 0x03;  // Address of sensor
    float expectedTemperature = 104.6f;  // Expected temperature
    float tolerance = 0.1f; 		   // Tolerance of sensor


    i2c_readRegister_ExpectAndReturn(tempRegisterAddress, 0x3ff); //Mock the i2c returning the value 0x3ff


    //Then
    float actualTemperature = tempSensor_getTemperature();
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature,actualTemperature);
}


#endif // TEST
