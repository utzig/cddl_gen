/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ztest.h>
#include "systematic.h"

void test_numbers(void)
{
	const uint8_t payload_numbers1[] = {
		0x01,
		0x21,
		0x05,
		0x18, 0x01, 0x00,
		0x19, 0x01, 0x02, 0x03, 0x04,
		0x38, 0x10, 0x00,
		0x19, 0xEE, 0x6B, 0x28, 0x00,
		0x20,
		0x00,
		0x01
	};

	Numbers_t numbers;
	zassert_true(cbor_decode_Numbers(payload_numbers1,
		sizeof(payload_numbers1), &numbers), NULL);
}


void test_main(void)
{
	ztest_test_suite(cbor_cddl_test5,
			 ztest_unit_test(test_numbers)
	);
	ztest_run_test_suite(cbor_cddl_test5);
}
