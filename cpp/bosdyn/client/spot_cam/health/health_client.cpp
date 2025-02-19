/**
 * Copyright (c) 2021 Boston Dynamics, Inc.  All rights reserved.
 *
 * Downloading, reproducing, distributing or otherwise using the SDK Software
 * is subject to the terms and conditions of the Boston Dynamics Software
 * Development Kit License (20191101-BDSDK-SL).
 */


#include "bosdyn/client/spot_cam/health/health_client.h"
#include "bosdyn/common/success_condition.h"

using namespace std::placeholders;

namespace bosdyn {

namespace client {

namespace spot_cam {

const char* HealthClient::s_default_service_name = "spot-cam-health";

const char* HealthClient::s_service_type = "bosdyn.api.spot_cam.HealthService";

std::shared_future<ClearBITEventsResultType> HealthClient::ClearBITEventsAsync(
    const RPCParameters& parameters) {
    std::promise<ClearBITEventsResultType> response;
    std::shared_future<ClearBITEventsResultType> future = response.get_future();
    BOSDYN_ASSERT_PRECONDITION(m_stub != nullptr, "Stub for service is unset!");

    ::bosdyn::api::spot_cam::ClearBITEventsRequest request;
    MessagePumpCallBase* one_time =
        InitiateAsyncCall<::bosdyn::api::spot_cam::ClearBITEventsRequest, ::bosdyn::api::spot_cam::ClearBITEventsResponse,
                          ::bosdyn::api::spot_cam::ClearBITEventsResponse>(
            request,
            std::bind(&::bosdyn::api::spot_cam::HealthService::Stub::AsyncClearBITEvents, m_stub.get(), _1, _2, _3),
            std::bind(&HealthClient::OnClearBITEventsComplete, this, _1, _2, _3, _4, _5),
            std::move(response), parameters);

    return future;
}

ClearBITEventsResultType HealthClient::ClearBITEvents(
    const RPCParameters& parameters) {
    return ClearBITEventsAsync(parameters).get();
}

void HealthClient::OnClearBITEventsComplete(
    MessagePumpCallBase* call, const ::bosdyn::api::spot_cam::ClearBITEventsRequest& request,
    ::bosdyn::api::spot_cam::ClearBITEventsResponse&& response, const grpc::Status& status,
    std::promise<ClearBITEventsResultType> promise) {
    ::bosdyn::common::Status ret_status = ProcessResponseAndGetFinalStatus<::bosdyn::api::spot_cam::ClearBITEventsResponse>(
        status, response, SDKErrorCode::Success);

    promise.set_value({ret_status, std::move(response)});
}

std::shared_future<GetBITStatusResultType> HealthClient::GetBITStatusAsync(
    const RPCParameters& parameters) {
    std::promise<GetBITStatusResultType> response;
    std::shared_future<GetBITStatusResultType> future = response.get_future();
    BOSDYN_ASSERT_PRECONDITION(m_stub != nullptr, "Stub for service is unset!");

    ::bosdyn::api::spot_cam::GetBITStatusRequest request;
    MessagePumpCallBase* one_time =
        InitiateAsyncCall<::bosdyn::api::spot_cam::GetBITStatusRequest, ::bosdyn::api::spot_cam::GetBITStatusResponse,
                          ::bosdyn::api::spot_cam::GetBITStatusResponse>(
            request,
            std::bind(&::bosdyn::api::spot_cam::HealthService::Stub::AsyncGetBITStatus, m_stub.get(), _1, _2, _3),
            std::bind(&HealthClient::OnGetBITStatusComplete, this, _1, _2, _3, _4, _5),
            std::move(response), parameters);

    return future;
}

GetBITStatusResultType HealthClient::GetBITStatus(
    const RPCParameters& parameters) {
    return GetBITStatusAsync(parameters).get();
}

void HealthClient::OnGetBITStatusComplete(
    MessagePumpCallBase* call, const ::bosdyn::api::spot_cam::GetBITStatusRequest& request,
    ::bosdyn::api::spot_cam::GetBITStatusResponse&& response, const grpc::Status& status,
    std::promise<GetBITStatusResultType> promise) {
    ::bosdyn::common::Status ret_status = ProcessResponseAndGetFinalStatus<::bosdyn::api::spot_cam::GetBITStatusResponse>(
        status, response, SDKErrorCode::Success);

    promise.set_value({ret_status, std::move(response)});
}


std::shared_future<GetTemperatureResultType> HealthClient::GetTemperatureAsync(
    const RPCParameters& parameters) {
    std::promise<GetTemperatureResultType> response;
    std::shared_future<GetTemperatureResultType> future = response.get_future();
    BOSDYN_ASSERT_PRECONDITION(m_stub != nullptr, "Stub for service is unset!");

    ::bosdyn::api::spot_cam::GetTemperatureRequest request;
    MessagePumpCallBase* one_time =
        InitiateAsyncCall<::bosdyn::api::spot_cam::GetTemperatureRequest, ::bosdyn::api::spot_cam::GetTemperatureResponse,
                          ::bosdyn::api::spot_cam::GetTemperatureResponse>(
            request,
            std::bind(&::bosdyn::api::spot_cam::HealthService::Stub::AsyncGetTemperature, m_stub.get(), _1, _2, _3),
            std::bind(&HealthClient::OnGetTemperatureComplete, this, _1, _2, _3, _4, _5),
            std::move(response), parameters);

    return future;
}

GetTemperatureResultType HealthClient::GetTemperature(
    const RPCParameters& parameters) {
    return GetTemperatureAsync(parameters).get();
}

void HealthClient::OnGetTemperatureComplete(
    MessagePumpCallBase* call, const ::bosdyn::api::spot_cam::GetTemperatureRequest& request,
    ::bosdyn::api::spot_cam::GetTemperatureResponse&& response, const grpc::Status& status,
    std::promise<GetTemperatureResultType> promise) {
    ::bosdyn::common::Status ret_status = ProcessResponseAndGetFinalStatus<::bosdyn::api::spot_cam::GetTemperatureResponse>(
        status, response, SDKErrorCode::Success);

    promise.set_value({ret_status, std::move(response)});
}

ServiceClient::QualityOfService HealthClient::GetQualityOfService() const {
    return QualityOfService::NORMAL;
}

void HealthClient::SetComms(const std::shared_ptr<grpc::ChannelInterface>& channel) {
    m_stub.reset(new ::bosdyn::api::spot_cam::HealthService::Stub(channel));
}

}  // namespace spot_cam
}  // namespace client

}  // namespace bosdyn
