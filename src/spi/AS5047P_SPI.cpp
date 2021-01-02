#include "AS5047P_SPI.h"

#include <Arduino.h>
#include "types/AS5047P_Types.h"

namespace AS5047P_ComBackend {

    AS5047P_SPI::AS5047P_SPI(const uint8_t chipSelectPinNo, const uint32_t spiSpeed) {
        
        this->__chipSelectPinNo = chipSelectPinNo;
        this->__spiSettings = SPISettings(spiSpeed, MSBFIRST, SPI_MODE1);

        pinMode(__chipSelectPinNo, OUTPUT);
        digitalWrite(__chipSelectPinNo, HIGH);

    }

    void AS5047P_SPI::write(const uint16_t regAddress, const uint16_t data) {

        // init spi interface
        SPI.begin();
        SPI.beginTransaction(__spiSettings);

        // set register address
        digitalWrite(__chipSelectPinNo, LOW);
        SPI.transfer16(regAddress);
        digitalWrite(__chipSelectPinNo, HIGH);
        delayMicroseconds(1);
        
        // write data
        digitalWrite(__chipSelectPinNo, LOW);
        SPI.transfer16(data);
        digitalWrite(__chipSelectPinNo, HIGH);
        delayMicroseconds(1);

        // close spi interface
        SPI.endTransaction();
        SPI.end();

    }


    uint16_t AS5047P_SPI::read(const uint16_t regAddress) {
        
        uint16_t receivedData = 0;
        
        // init spi interface
        SPI.begin();
        SPI.beginTransaction(__spiSettings);

        // set register address
        digitalWrite(__chipSelectPinNo, LOW);
        SPI.transfer16(regAddress);
        digitalWrite(__chipSelectPinNo, HIGH);
        delayMicroseconds(1);
        
        // write nop & reading data
        digitalWrite(__chipSelectPinNo, LOW);
        AS5047P_types::SPI_Command_Frame_t nopFrame(AS5047P_types::NOP_t::REG_ADDRESS, AS5047P_TYPES_READ_CMD);
        receivedData = SPI.transfer16(AS5047P_types::SPI_Command_Frame_t::ValuesToRaw(&nopFrame.values));
        digitalWrite(__chipSelectPinNo, HIGH);
        delayMicroseconds(1);
        
        // close spi interface
        SPI.endTransaction();
        SPI.end();

        return receivedData;

    }
}
