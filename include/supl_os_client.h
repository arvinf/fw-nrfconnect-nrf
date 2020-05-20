/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#ifndef SUPL_OS_CLIENT_H_
#define SUPL_OS_CLIENT_H_

#include <nrf_socket.h>
#include <supl_session.h>

#if CONFIG_NRF9160_GPS
#include <drivers/gps.h>
#endif
/**
 * @file supl_os_client.h
 *
 * @defgroup supl_os SUPL OS client
 *
 * @{
 **/

/**
 *
 * @brief Start a SUPL session
 *
 * @param[in] agps_request This contain the information about the AGPS data
 *                         that the GPS module is requesting from the server.
 *
 * @return 0  SUPL session was successful.
 *         <0 SUPL session failed.
 */
#if CONFIG_NRF9160_GPS
int supl_session(const struct gps_agps_request *const agps_request);
#else
int supl_session(const nrf_gnss_agps_data_frame_t *const agps_request);
#endif

/**
 * @brief Setup the API and the buffers required by
 *        the SUPL client libray.
 *
 * @param[in] api Function pointers to the API required by SUPL client library
 *                to work.
 *
 * @return 0  SUPL client library was initialized successfully.
 *         <0 Failed to initialize the SUPL client library.
 */
int supl_init(const struct supl_api *const api);

/** @} */

#endif /* SUPL_OS_CLIENT_H_ */
