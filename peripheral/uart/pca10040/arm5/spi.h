#include <stdbool.h>
#include <stdint.h>
#include "nrf_drv_spi.h"

bool spi_init();
void spi_event_handler(nrf_drv_spi_evt_t const * p_event);
bool spi_sci_cmd(uint32_t *sci_cmd);
bool spi_sdi_data(uint32_t *sdi_data, uint32_t sdi_data_lenght);