// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "Configuration.h"
#include <espMqttClient.h>
#include <TaskSchedulerDeclarations.h>

class MqttHandlePowerLimiterClass {
public:
    void init(Scheduler& scheduler);

private:
    void loop();
    void onCmdMode(const espMqttClientTypes::MessageProperties& properties, const char* topic, const uint8_t* payload, size_t len, size_t index, size_t total);

    Task _loopTask;

    uint32_t _lastPublishStats;
    uint32_t _lastPublish;

};

extern MqttHandlePowerLimiterClass MqttHandlePowerLimiter;