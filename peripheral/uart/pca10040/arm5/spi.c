#include <stdbool.h>
#include <stdint.h>
#include "spi.h"
#include "nrf_drv_spi.h"
#include "app_uart.h"
#include <stdio.h>
#include "app_error.h"

#define SPI_INSTANCE  0 /**< SPI instance index. */
#define TEST_STRING "Nordic"

#define SPI_CS_PIN 29 /**< SPI CS Pin.*/


static volatile bool spi_xfer_done;  /**< Flag used to indicate that SPI instance completed the transfer. */
static uint8_t       m_tx_buf[] = TEST_STRING;           /**< TX buffer. */
static uint8_t       m_rx_buf[sizeof(TEST_STRING)+1];    /**< RX buffer. */
static const nrf_drv_spi_t spi = NRF_DRV_SPI_INSTANCE(SPI_INSTANCE);  /**< SPI instance. */
static const uint8_t m_length = sizeof(m_tx_buf);        /**< Transfer length. */

bool spi_init()
{
	nrf_drv_spi_config_t spi_config = NRF_DRV_SPI_DEFAULT_CONFIG(SPI_INSTANCE);
    spi_config.ss_pin = SPI_CS_PIN;
    APP_ERROR_CHECK(nrf_drv_spi_init(&spi, &spi_config, spi_event_handler));
	return true;
}

void spi_event_handler(nrf_drv_spi_evt_t const * p_event)
{
    spi_xfer_done = true;
    printf("Transfer completed.\r\n");
    if (m_rx_buf[0] != 0)
    {
        printf(" Received: %s\r\n",m_rx_buf);
    }
}
bool spi_sci_cmd(uint32_t *sci_cmd)
{
	nrf_drv_spi_transfer(&spi, (const uint8_t*)sci_cmd, , m_rx_buf, m_length);
	return true;
}

bool spi_sdi_data(uint32_t *sdi_data, uint32_t sdi_data_lenght)
{
	
	return true;
}