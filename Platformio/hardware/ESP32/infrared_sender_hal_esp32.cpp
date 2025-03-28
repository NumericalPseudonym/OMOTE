#include <Arduino.h>
#include <string>
#include <list>
#include <sstream>
#include <IRremoteESP8266.h>
#include <IRsend.h>

#if (OMOTE_HARDWARE_REV >= 5)
const uint8_t IR_LED_GPIO = 5; // IR LED output
#else
const uint8_t IR_LED_GPIO = 33; // IR LED output
#endif

IRsend IrSender(IR_LED_GPIO, true);

void init_infraredSender_HAL(void)
{
  // IR Pin Definition
  pinMode(IR_LED_GPIO, OUTPUT);
  digitalWrite(IR_LED_GPIO, HIGH); // HIGH off - LOW on

  IrSender.begin();
}

// IR protocols
enum IRprotocols
{
  IR_PROTOCOL_GC = 0,
  IR_PROTOCOL_NEC = 1,
  IR_PROTOCOL_SAMSUNG = 2,
  IR_PROTOCOL_SONY = 3,
  IR_PROTOCOL_RC5 = 4,
  IR_PROTOCOL_DENON = 5,
  IR_PROTOCOL_SAMSUNG36 = 6,
  IR_PROTOCOL_PRONTO = 7,
  IR_PROTOCOL_SONY12 = 8,
  IR_PROTOCOL_SONY15 = 9,
};

void sendIRcode_HAL(int protocol, std::list<std::string> commandPayloads, std::string additionalPayload)
{

  // first determine if data was provided by commandPayload or by additionalPayload. Only one of these will be used.
  std::string::size_type sz = 0; // alias of size_t
  std::string dataStr;
  uint64_t data;
  if (commandPayloads.empty() && (additionalPayload == ""))
  {
    Serial.printf("sendIRcode_HAL: cannot send IR command, because both data and payload are empty.\r\n");
    return;
  }
  else
  {
    if (additionalPayload != "")
    {
      Serial.printf("sendIRcode_HAL: Setting data stream to additional payload.\r\n");
      dataStr = additionalPayload;
    }
    else
    {
      auto current = commandPayloads.begin();
      dataStr = *current;
    }
  }

  switch (protocol)
  {
    case IR_PROTOCOL_GC:
    {
      // first create array of needed size
      std::string::difference_type size = std::count(dataStr.begin(), dataStr.end(), ',');
      size += 1;
      uint16_t *buf = new uint16_t[size];
      // now get comma separated values and fill array
      int pos = 0;
      std::stringstream ss(dataStr);
      while (ss.good())
      {
        std::string valueStr;
        std::getline(ss, valueStr, ',');
        // https://cplusplus.com/reference/string/stoull/
        data = std::stoull(valueStr, &sz, 0);
        // Serial.printf("  next string value %s (%" PRIu64 ")\r\n", valueStr.c_str(), data);
        buf[pos] = data;
        pos += 1;
      }
      Serial.printf("sendIRcode_HAL: will send IR GC, array size '%d'.\r\n", size);
      IrSender.sendGC(buf, size);
      delete[] buf;
      break;
    }

    case IR_PROTOCOL_NEC:
    {
      data = std::stoull(dataStr, &sz, 0);
      Serial.printf("sendIRcode_HAL: will send IR NEC, data '%s' '%" PRIu64 "'.\r\n", dataStr.c_str(), data);
      IrSender.sendNEC(data);
      break;
    }

    case IR_PROTOCOL_SAMSUNG:
    {
      data = std::stoull(dataStr, &sz, 0);
      Serial.printf("sendIRcode_HAL: will send IR SAMSUNG, data '%s' '%" PRIu64 "'.\r\n", dataStr.c_str(), data);
      IrSender.sendSAMSUNG(data);
      break;
    }

    case IR_PROTOCOL_SONY12:
    {
      data = std::stoull(dataStr, &sz, 0);
      Serial.printf("sendIRcode_HAL: will send IR SONY 15 bit, data '%s' '%" PRIu64 "'.\r\n", dataStr.c_str(), data);
      IrSender.sendSony(data, 12);
      break;
    }

    case IR_PROTOCOL_SONY: /* fallthrough */
    case IR_PROTOCOL_SONY15:
    {
      data = std::stoull(dataStr, &sz, 0);
      Serial.printf("sendIRcode_HAL: will send IR SONY 15 bit, data '%s' '%" PRIu64 "'.\r\n", dataStr.c_str(), data);
      IrSender.sendSony(data, 15);
      break;
    }

    case IR_PROTOCOL_RC5:
    {
      data = std::stoull(dataStr, &sz, 0);
      Serial.printf("sendIRcode_HAL: will send IR RC5, data '%s' '%" PRIu64 "'.\r\n", dataStr.c_str(), data);
      IrSender.sendRC5(IrSender.encodeRC5X(0x00, data));
      break;
    }

    case IR_PROTOCOL_DENON:
    {
      data = std::stoull(dataStr, &sz, 0);
      Serial.printf("sendIRcode_HAL: will send IR DENON 48 bit, data '%s' '%" PRIu64 "'.\r\n", dataStr.c_str(), data);
      IrSender.sendDenon(data, 48);
      break;
    }

    case IR_PROTOCOL_SAMSUNG36:
    {
      data = std::stoull(dataStr, &sz, 0);
      Serial.printf("sendIRcode_HAL: will send IR SAMSUNG36, data '%s' '%" PRIu64 "'.\r\n", dataStr.c_str(), data);
      IrSender.sendSamsung36(data);
      break;
    }

    case IR_PROTOCOL_PRONTO:
    {
      // Pronto codes are typically represented in hexadecimal. You will need to convert the code to an array of
      // integers, and calculate it's length.
      // Ex: 0000 0067 0000 0015 0060 0018 0018 0018 0030 0018 0030 0018 0030 0018 0018 0018 0030 0018 0018 0018 0018 0018 0030 0018 0018 0018 0030 0018 0030 0018 0030 0018 0018 0018 0018 0018 0030 0018 0018 0018 0018 0018 0030 0018 0018 03f6" converts to: uint16_t prontoCode[46] = { 0x0000, 0x0067, 0x0000, 0x0015, 0x0060, 0x0018, 0x0018, 0x0018, 0x0030, 0x0018, 0x0030, 0x0018, 0x0030, 0x0018, 0x0018, 0x0018, 0x0030, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0030, 0x0018, 0x0018, 0x0018, 0x0030, 0x0018, 0x0030, 0x0018, 0x0030, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0030, 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0030, 0x0018, 0x0018, 0x03f6
      //
      // First create array of needed size by:
      // 1. Counting Spaces
      // 2. Adding one to account for the last element.
      
      Serial.printf("sendIRcode_HAL: will send IR PRONTO Hex, data '%s'.\r\n", dataStr.c_str());

      std::string::difference_type size = std::count(dataStr.begin(), dataStr.end(), ' ');
      size += 1;
      uint16_t singleCommandBlock = 0;
      uint16_t *encodedCommand = new uint16_t[size];
      // now get space separated values and fill array
      int pos = 0;
      std::stringstream ssDataStr(dataStr);
      while (ssDataStr.good())
      {
        std::string valueAsStr;
        std::getline(ssDataStr, valueAsStr, ' ');
        // https://cplusplus.com/reference/string/stoull/
        singleCommandBlock = std::stoull(valueAsStr, &sz, 16);
        
        Serial.printf("      Position %d: '%s' '%" PRIu16 "'.\r\n", pos, valueAsStr.c_str(), singleCommandBlock);
        
        encodedCommand[pos] = singleCommandBlock;
        pos++;
      }

      Serial.printf("sendIRcode_HAL: sending IR PRONTO Hex. Size '%d'.\r\n", size);

      int8_t result = IrSender.sendPronto(encodedCommand, size, 3);
      
      Serial.printf("sendIRcode_HAL: sending ID PRONTO Hex result. '%d'.\r\n", result);

      break;
    }
  }
}