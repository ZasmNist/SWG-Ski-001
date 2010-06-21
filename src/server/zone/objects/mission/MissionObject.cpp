/*
 *	server/zone/objects/mission/MissionObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "MissionObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/waypoint/WaypointObject.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/mission/MissionObserver.h"

/*
 *	MissionObjectStub
 */

MissionObject::MissionObject() : IntangibleObject(DummyConstructorParameter::instance()) {
	_impl = new MissionObjectImplementation();
	_impl->_setStub(this);
}

MissionObject::MissionObject(DummyConstructorParameter* param) : IntangibleObject(param) {
}

MissionObject::~MissionObject() {
}


void MissionObject::setRefreshCounter(int ctr, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addSignedIntParameter(ctr);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		((MissionObjectImplementation*) _impl)->setRefreshCounter(ctr, notifyClient);
}

void MissionObject::setTypeCRC(unsigned int crc, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addUnsignedIntParameter(crc);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		((MissionObjectImplementation*) _impl)->setTypeCRC(crc, notifyClient);
}

void MissionObject::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		((MissionObjectImplementation*) _impl)->initializeTransientMembers();
}

void MissionObject::sendBaselinesTo(SceneObject* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((MissionObjectImplementation*) _impl)->sendBaselinesTo(player);
}

WaypointObject* MissionObject::getWaypointToMission() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return (WaypointObject*) method.executeWithObjectReturn();
	} else
		return ((MissionObjectImplementation*) _impl)->getWaypointToMission();
}

unsigned int MissionObject::getTypeCRC() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((MissionObjectImplementation*) _impl)->getTypeCRC();
}

int MissionObject::getRewardCredits() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithSignedIntReturn();
	} else
		return ((MissionObjectImplementation*) _impl)->getRewardCredits();
}

UnicodeString MissionObject::getCreatorName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		method.executeWithUnicodeReturn(_return_getCreatorName);
		return _return_getCreatorName;
	} else
		return ((MissionObjectImplementation*) _impl)->getCreatorName();
}

int MissionObject::getDifficultyLevel() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithSignedIntReturn();
	} else
		return ((MissionObjectImplementation*) _impl)->getDifficultyLevel();
}

StringId* MissionObject::getMissionDescription() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((MissionObjectImplementation*) _impl)->getMissionDescription();
}

StringId* MissionObject::getMissionTitle() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((MissionObjectImplementation*) _impl)->getMissionTitle();
}

String MissionObject::getTargetName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		method.executeWithAsciiReturn(_return_getTargetName);
		return _return_getTargetName;
	} else
		return ((MissionObjectImplementation*) _impl)->getTargetName();
}

int MissionObject::getRefreshCounter() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithSignedIntReturn();
	} else
		return ((MissionObjectImplementation*) _impl)->getRefreshCounter();
}

unsigned int MissionObject::getTargetTemplateCRC() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((MissionObjectImplementation*) _impl)->getTargetTemplateCRC();
}

bool MissionObject::isSurveyMission() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithBooleanReturn();
	} else
		return ((MissionObjectImplementation*) _impl)->isSurveyMission();
}

/*
 *	MissionObjectImplementation
 */

MissionObjectImplementation::MissionObjectImplementation(DummyConstructorParameter* param) : IntangibleObjectImplementation(param) {
	_initializeImplementation();
}

MissionObjectImplementation::~MissionObjectImplementation() {
}


void MissionObjectImplementation::finalize() {
}

void MissionObjectImplementation::_initializeImplementation() {
	_setClassHelper(MissionObjectHelper::instance());

	_serializationHelperMethod();
}

void MissionObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (MissionObject*) stub;
	IntangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* MissionObjectImplementation::_getStub() {
	return _this;
}

MissionObjectImplementation::operator const MissionObject*() {
	return _this;
}

void MissionObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void MissionObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void MissionObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void MissionObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void MissionObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void MissionObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void MissionObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void MissionObjectImplementation::_serializationHelperMethod() {
	IntangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("MissionObject");

	addSerializableVariable("waypointToMission", &waypointToMission);
	addSerializableVariable("missionObserver", &missionObserver);
	addSerializableVariable("typeCRC", &typeCRC);
	addSerializableVariable("difficultyLevel", &difficultyLevel);
	addSerializableVariable("creatorName", &creatorName);
	addSerializableVariable("rewardCredits", &rewardCredits);
	addSerializableVariable("missionDescription", &missionDescription);
	addSerializableVariable("missionTitle", &missionTitle);
	addSerializableVariable("refreshCounter", &refreshCounter);
	addSerializableVariable("targetName", &targetName);
	addSerializableVariable("targetTemplateCRC", &targetTemplateCRC);
}

MissionObjectImplementation::MissionObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/mission/MissionObject.idl(93):  		typeCRC = SURVEY;
	typeCRC = SURVEY;
	// server/zone/objects/mission/MissionObject.idl(95):  		refreshCounter = 0;
	refreshCounter = 0;
	// server/zone/objects/mission/MissionObject.idl(97):  		targetTemplateCRC = 2640304325;
	targetTemplateCRC = 2640304325;
	// server/zone/objects/mission/MissionObject.idl(99):  		missionDescription.setStringId("mission/mission_npc_survey_neutral_easy", "m1o");
	(&missionDescription)->setStringId("mission/mission_npc_survey_neutral_easy", "m1o");
	// server/zone/objects/mission/MissionObject.idl(100):  		missionTitle.setStringId("mission/mission_npc_survey_neutral_easy", "m1t");
	(&missionTitle)->setStringId("mission/mission_npc_survey_neutral_easy", "m1t");
	// server/zone/objects/mission/MissionObject.idl(101):  		targetName = "Testing target name";
	targetName = "Testing target name";
	// server/zone/objects/mission/MissionObject.idl(102):  		difficultyLevel = 50;
	difficultyLevel = 50;
	// server/zone/objects/mission/MissionObject.idl(104):  		rewardCredits = 100;
	rewardCredits = 100;
	// server/zone/objects/mission/MissionObject.idl(106):  		Logger.setLoggingName("MissionObject");
	Logger::setLoggingName("MissionObject");
}

WaypointObject* MissionObjectImplementation::getWaypointToMission() {
	// server/zone/objects/mission/MissionObject.idl(116):  		return waypointToMission;
	return waypointToMission;
}

unsigned int MissionObjectImplementation::getTypeCRC() {
	// server/zone/objects/mission/MissionObject.idl(120):  		return typeCRC;
	return typeCRC;
}

int MissionObjectImplementation::getRewardCredits() {
	// server/zone/objects/mission/MissionObject.idl(124):  		return rewardCredits;
	return rewardCredits;
}

UnicodeString MissionObjectImplementation::getCreatorName() {
	// server/zone/objects/mission/MissionObject.idl(128):  		return creatorName;
	return creatorName;
}

int MissionObjectImplementation::getDifficultyLevel() {
	// server/zone/objects/mission/MissionObject.idl(132):  		return difficultyLevel;
	return difficultyLevel;
}

StringId* MissionObjectImplementation::getMissionDescription() {
	// server/zone/objects/mission/MissionObject.idl(137):  		return missionDescription;
	return (&missionDescription);
}

StringId* MissionObjectImplementation::getMissionTitle() {
	// server/zone/objects/mission/MissionObject.idl(142):  		return missionTitle;
	return (&missionTitle);
}

String MissionObjectImplementation::getTargetName() {
	// server/zone/objects/mission/MissionObject.idl(146):  		return targetName;
	return targetName;
}

int MissionObjectImplementation::getRefreshCounter() {
	// server/zone/objects/mission/MissionObject.idl(150):  		return refreshCounter;
	return refreshCounter;
}

unsigned int MissionObjectImplementation::getTargetTemplateCRC() {
	// server/zone/objects/mission/MissionObject.idl(154):  		return targetTemplateCRC;
	return targetTemplateCRC;
}

bool MissionObjectImplementation::isSurveyMission() {
	// server/zone/objects/mission/MissionObject.idl(158):  		return false;
	return false;
}

/*
 *	MissionObjectAdapter
 */

MissionObjectAdapter::MissionObjectAdapter(MissionObjectImplementation* obj) : IntangibleObjectAdapter(obj) {
}

Packet* MissionObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		setRefreshCounter(inv->getSignedIntParameter(), inv->getBooleanParameter());
		break;
	case 7:
		setTypeCRC(inv->getUnsignedIntParameter(), inv->getBooleanParameter());
		break;
	case 8:
		initializeTransientMembers();
		break;
	case 9:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case 10:
		resp->insertLong(getWaypointToMission()->_getObjectID());
		break;
	case 11:
		resp->insertInt(getTypeCRC());
		break;
	case 12:
		resp->insertSignedInt(getRewardCredits());
		break;
	case 13:
		resp->insertUnicode(getCreatorName());
		break;
	case 14:
		resp->insertSignedInt(getDifficultyLevel());
		break;
	case 15:
		resp->insertAscii(getTargetName());
		break;
	case 16:
		resp->insertSignedInt(getRefreshCounter());
		break;
	case 17:
		resp->insertInt(getTargetTemplateCRC());
		break;
	case 18:
		resp->insertBoolean(isSurveyMission());
		break;
	default:
		return NULL;
	}

	return resp;
}

void MissionObjectAdapter::setRefreshCounter(int ctr, bool notifyClient) {
	((MissionObjectImplementation*) impl)->setRefreshCounter(ctr, notifyClient);
}

void MissionObjectAdapter::setTypeCRC(unsigned int crc, bool notifyClient) {
	((MissionObjectImplementation*) impl)->setTypeCRC(crc, notifyClient);
}

void MissionObjectAdapter::initializeTransientMembers() {
	((MissionObjectImplementation*) impl)->initializeTransientMembers();
}

void MissionObjectAdapter::sendBaselinesTo(SceneObject* player) {
	((MissionObjectImplementation*) impl)->sendBaselinesTo(player);
}

WaypointObject* MissionObjectAdapter::getWaypointToMission() {
	return ((MissionObjectImplementation*) impl)->getWaypointToMission();
}

unsigned int MissionObjectAdapter::getTypeCRC() {
	return ((MissionObjectImplementation*) impl)->getTypeCRC();
}

int MissionObjectAdapter::getRewardCredits() {
	return ((MissionObjectImplementation*) impl)->getRewardCredits();
}

UnicodeString MissionObjectAdapter::getCreatorName() {
	return ((MissionObjectImplementation*) impl)->getCreatorName();
}

int MissionObjectAdapter::getDifficultyLevel() {
	return ((MissionObjectImplementation*) impl)->getDifficultyLevel();
}

String MissionObjectAdapter::getTargetName() {
	return ((MissionObjectImplementation*) impl)->getTargetName();
}

int MissionObjectAdapter::getRefreshCounter() {
	return ((MissionObjectImplementation*) impl)->getRefreshCounter();
}

unsigned int MissionObjectAdapter::getTargetTemplateCRC() {
	return ((MissionObjectImplementation*) impl)->getTargetTemplateCRC();
}

bool MissionObjectAdapter::isSurveyMission() {
	return ((MissionObjectImplementation*) impl)->isSurveyMission();
}

/*
 *	MissionObjectHelper
 */

MissionObjectHelper* MissionObjectHelper::staticInitializer = MissionObjectHelper::instance();

MissionObjectHelper::MissionObjectHelper() {
	className = "MissionObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void MissionObjectHelper::finalizeHelper() {
	MissionObjectHelper::finalize();
}

DistributedObject* MissionObjectHelper::instantiateObject() {
	return new MissionObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* MissionObjectHelper::instantiateServant() {
	return new MissionObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* MissionObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new MissionObjectAdapter((MissionObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

