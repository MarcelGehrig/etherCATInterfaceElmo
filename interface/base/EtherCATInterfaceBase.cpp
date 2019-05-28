#include "EtherCATInterfaceBase.hpp"

using namespace etherCATInterface;

EtherCATInterfaceBase::EtherCATInterfaceBase(ecmasterlib::EcMasterlibMain* etherCATStack) :
etherCATStack(etherCATStack)
{
	outBuffer = etherCATStack->getOutBuffer();
	inBuffer = etherCATStack->getInBuffer();
	memset(outBuffer, 0, bytesPerPDOFrameTx);
}

void EtherCATInterfaceBase::set8bit(uint32_t offsetInByte, int8_t payload)
{
	set8bit(offsetInByte, 0, payload);
}

void EtherCATInterfaceBase::set8bit(uint32_t offsetInByte, uint32_t driveNumber, int8_t payload)
{	
	if(checkOffset(offsetInByte)) {
		etherCATStack->setByte(outBuffer + driveNumber*bytesPerPDOFrameTx + offsetInByte, payload);
	}
}

void EtherCATInterfaceBase::set8bit(uint32_t offsetInByte, uint8_t payload)
{
	set8bit(offsetInByte, 0, payload);
}

void EtherCATInterfaceBase::set8bit(uint32_t offsetInByte, uint32_t driveNumber, uint8_t payload)
{
	if(checkOffset(offsetInByte)) {
		etherCATStack->setByte(outBuffer + driveNumber*bytesPerPDOFrameTx + offsetInByte, payload);
	}
}

void EtherCATInterfaceBase::set16bit(uint32_t offsetInByte, int16_t payload)
{
	set16bit(offsetInByte, 0, payload);
}

void EtherCATInterfaceBase::set16bit(uint32_t offsetInByte, uint32_t driveNumber, int16_t payload)
{
	if(checkOffset(offsetInByte)) {
		etherCATStack->setWord(outBuffer + driveNumber*bytesPerPDOFrameTx + offsetInByte, payload);
	}
}

void EtherCATInterfaceBase::set16bit(uint32_t offsetInByte, uint16_t payload)
{
	set16bit(offsetInByte, 0, payload);
}

void EtherCATInterfaceBase::set16bit(uint32_t offsetInByte, uint32_t driveNumber, uint16_t payload)
{
	if(checkOffset(offsetInByte)) {
		etherCATStack->setWord(outBuffer + driveNumber*bytesPerPDOFrameTx + offsetInByte, payload);
	}
}

void EtherCATInterfaceBase::set32bit(uint32_t offsetInByte, int32_t payload)
{
	set32bit(offsetInByte, 0, payload);
}

void EtherCATInterfaceBase::set32bit(uint32_t offsetInByte, uint32_t driveNumber, int32_t payload)
{
	if(checkOffset(offsetInByte)) {
		etherCATStack->setDWord(outBuffer + driveNumber*bytesPerPDOFrameTx + offsetInByte, payload);
	}
}

void EtherCATInterfaceBase::set32bit(uint32_t offsetInByte, uint32_t payload)
{
	set32bit(offsetInByte, 0, payload);
}

void EtherCATInterfaceBase::set32bit(uint32_t offsetInByte, uint32_t driveNumber, uint32_t payload)
{
	if(checkOffset(offsetInByte)) {
		etherCATStack->setDWord(outBuffer + driveNumber*bytesPerPDOFrameTx + offsetInByte, payload);
	}
}



uint8_t EtherCATInterfaceBase::get8bit(uint32_t offsetInByte)
{
	get8bit(offsetInByte, 0);
}

uint8_t EtherCATInterfaceBase::get8bit(uint32_t offsetInByte, uint32_t driveNumber)
{
	if(checkOffset(offsetInByte)) {
		return (uint8_t)etherCATStack->getFrmByte(inBuffer + driveNumber*bytesPerPDOFrameTx + offsetInByte);
	}
}

uint16_t EtherCATInterfaceBase::get16bit(uint32_t offsetInByte)
{
	get16bit(offsetInByte, 0);
}

uint16_t EtherCATInterfaceBase::get16bit(uint32_t offsetInByte, uint32_t driveNumber)
{
	if(checkOffset(offsetInByte)) {
		return (uint16_t)etherCATStack->getFrmWord(inBuffer + driveNumber*bytesPerPDOFrameTx + offsetInByte);
	}
}

uint32_t EtherCATInterfaceBase::get32bit(uint32_t offsetInByte)
{
	get32bit(offsetInByte, 0);
}

uint32_t EtherCATInterfaceBase::get32bit(uint32_t offsetInByte, uint32_t driveNumber)
{
	if(checkOffset(offsetInByte)) {
		return (uint32_t)etherCATStack->getFrmDWord(inBuffer + driveNumber*bytesPerPDOFrameTx + offsetInByte);
	}
}



//private:
bool EtherCATInterfaceBase::checkOffset(int offsetInByte)
{
	if(offsetInByte < 0) {
		std::cout << "ERROR EtherCATInterfaceBase::checkOffset():   the PDO offset is not defined in EtherCATInterface" << std::endl;
		return false;
	}
	else {
		return true;
	}
}

bool EtherCATInterfaceBase::checkMaskedBits(uint16_t variable, uint16_t compareWord, uint16_t mask)
{
	variable = variable & mask;
	compareWord = compareWord & mask;
	if ( variable == compareWord ) return true;
	else return false;
}



