/**
 * @file        processing.hpp
 * @authors     Fabian Jenelten
 * @date        04.08, 2021
 * @affiliation ETH RSL
 * @brief       Processing filter (everything that is not smoothing or inpainting).
 */

#pragma once

// grid map.
#include <grid_map_core/grid_map_core.hpp>

namespace grid_map {
namespace processing {

/**
 * @brief Replaces values by max in region. In-place operation (layerIn = layerOut) is NOT supported. Supports nan values.
 * @param map           grid map
 * @param layerIn       reference layer (filter is applied wrt this layer)
 * @param layerOut      output layer (filtered map is written into this layer)
 * @param mask          Filter is applied only where mask contains values of 1 and omitted where values are nan. If mask is an empty matrix,
 *                      applies unmasked dilation.
 * @param kernelSize    vicinity considered by filter (mist be odd).
 * @param inpaint       if true, also replaces potential nan values by the minimum
 */
void dilate(grid_map::GridMap& map, const std::string& layerIn, const std::string& layerOut,
            const grid_map::Matrix& mask = grid_map::Matrix(), int kernelSize = 9, bool inpaint);

/**
 * @brief Replaces values by min in region. In-place operation (layerIn = layerOut) is NOT supported. Supports nan values.
 * @param map           grid map
 * @param layerIn       reference layer (filter is applied wrt this layer)
 * @param layerOut      output layer (filtered map is written into this layer)
 * @param mask          Filter is applied only where mask contains values of 1 and omitted where values are nan. If mask is an empty matrix,
 *                      applies unmasked dilation.
 * @param kernelSize    vicinity considered by filter (mist be odd).
 * @param inpaint       if true, also replaces potential nan values by the minimum
 */
void erode(grid_map::GridMap& map, const std::string& layerIn, const std::string& layerOut,
           const grid_map::Matrix& mask = grid_map::Matrix(), int kernelSize = 9, bool inpaint = true);

/**
 * @brief Extracts a thin layer of height values, surrounding patches of nan-values. In-place operation (layerIn = layerOut) is NOT
 * supported. Supports nan values.
 * @param map           grid map
 * @param layerIn       reference layer (filter is applied wrt this layer)
 * @param layerOut      output layer (filtered map is written into this layer)
 */
void outline(grid_map::GridMap& map, const std::string& layerIn, const std::string& layerOut);
}  // namespace processing
}  // namespace grid_map
