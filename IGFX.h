#pragma once

#include "ICore.h"

#include <stdint.h>

#define ALT_GFX_HANDLE(_name) \
    struct _name              \
    {                         \
        uint16_t idx;         \
    };                        \
    inline bool isValid(_name _handle) { return alt::IGFX::kInvalidHandle != _handle.idx; }

#define ALT_GFX_INVALID_HANDLE    \
    {                             \
        alt::IGFX::kInvalidHandle \
    }

#define ALT_GFX_API_VERSION UINT32_C(108)

/**
 * Color RGB/alpha/depth write. When it's not specified write will be disabled.
 *
 */
#define ALT_GFX_STATE_WRITE_R UINT64_C(0x0000000000000001) //!< Enable R write.
#define ALT_GFX_STATE_WRITE_G UINT64_C(0x0000000000000002) //!< Enable G write.
#define ALT_GFX_STATE_WRITE_B UINT64_C(0x0000000000000004) //!< Enable B write.
#define ALT_GFX_STATE_WRITE_A UINT64_C(0x0000000000000008) //!< Enable alpha write.
#define ALT_GFX_STATE_WRITE_Z UINT64_C(0x0000004000000000) //!< Enable depth write.
/// Enable RGB write.
#define ALT_GFX_STATE_WRITE_RGB (0 | ALT_GFX_STATE_WRITE_R | ALT_GFX_STATE_WRITE_G | ALT_GFX_STATE_WRITE_B)

/// Write all channels mask.
#define ALT_GFX_STATE_WRITE_MASK (0 | ALT_GFX_STATE_WRITE_RGB | ALT_GFX_STATE_WRITE_A | ALT_GFX_STATE_WRITE_Z)

/**
 * Depth test state. When `ALT_GFX_STATE_DEPTH_` is not specified depth test will be disabled.
 *
 */
#define ALT_GFX_STATE_DEPTH_TEST_LESS UINT64_C(0x0000000000000010)     //!< Enable depth test, less.
#define ALT_GFX_STATE_DEPTH_TEST_LEQUAL UINT64_C(0x0000000000000020)   //!< Enable depth test, less or equal.
#define ALT_GFX_STATE_DEPTH_TEST_EQUAL UINT64_C(0x0000000000000030)    //!< Enable depth test, equal.
#define ALT_GFX_STATE_DEPTH_TEST_GEQUAL UINT64_C(0x0000000000000040)   //!< Enable depth test, greater or equal.
#define ALT_GFX_STATE_DEPTH_TEST_GREATER UINT64_C(0x0000000000000050)  //!< Enable depth test, greater.
#define ALT_GFX_STATE_DEPTH_TEST_NOTEQUAL UINT64_C(0x0000000000000060) //!< Enable depth test, not equal.
#define ALT_GFX_STATE_DEPTH_TEST_NEVER UINT64_C(0x0000000000000070)    //!< Enable depth test, never.
#define ALT_GFX_STATE_DEPTH_TEST_ALWAYS UINT64_C(0x0000000000000080)   //!< Enable depth test, always.
#define ALT_GFX_STATE_DEPTH_TEST_SHIFT 4                               //!< Depth test state bit shift
#define ALT_GFX_STATE_DEPTH_TEST_MASK UINT64_C(0x00000000000000f0)     //!< Depth test state bit mask

/**
 * Use ALT_GFX_STATE_BLEND_FUNC(_src, _dst) or ALT_GFX_STATE_BLEND_FUNC_SEPARATE(_srcRGB, _dstRGB, _srcA, _dstA)
 * helper macros.
 *
 */
#define ALT_GFX_STATE_BLEND_ZERO UINT64_C(0x0000000000001000)          //!< 0, 0, 0, 0
#define ALT_GFX_STATE_BLEND_ONE UINT64_C(0x0000000000002000)           //!< 1, 1, 1, 1
#define ALT_GFX_STATE_BLEND_SRC_COLOR UINT64_C(0x0000000000003000)     //!< Rs, Gs, Bs, As
#define ALT_GFX_STATE_BLEND_INV_SRC_COLOR UINT64_C(0x0000000000004000) //!< 1-Rs, 1-Gs, 1-Bs, 1-As
#define ALT_GFX_STATE_BLEND_SRC_ALPHA UINT64_C(0x0000000000005000)     //!< As, As, As, As
#define ALT_GFX_STATE_BLEND_INV_SRC_ALPHA UINT64_C(0x0000000000006000) //!< 1-As, 1-As, 1-As, 1-As
#define ALT_GFX_STATE_BLEND_DST_ALPHA UINT64_C(0x0000000000007000)     //!< Ad, Ad, Ad, Ad
#define ALT_GFX_STATE_BLEND_INV_DST_ALPHA UINT64_C(0x0000000000008000) //!< 1-Ad, 1-Ad, 1-Ad ,1-Ad
#define ALT_GFX_STATE_BLEND_DST_COLOR UINT64_C(0x0000000000009000)     //!< Rd, Gd, Bd, Ad
#define ALT_GFX_STATE_BLEND_INV_DST_COLOR UINT64_C(0x000000000000a000) //!< 1-Rd, 1-Gd, 1-Bd, 1-Ad
#define ALT_GFX_STATE_BLEND_SRC_ALPHA_SAT UINT64_C(0x000000000000b000) //!< f, f, f, 1; f = min(As, 1-Ad)
#define ALT_GFX_STATE_BLEND_FACTOR UINT64_C(0x000000000000c000)        //!< Blend factor
#define ALT_GFX_STATE_BLEND_INV_FACTOR UINT64_C(0x000000000000d000)    //!< 1-Blend factor
#define ALT_GFX_STATE_BLEND_SHIFT 12                                   //!< Blend state bit shift
#define ALT_GFX_STATE_BLEND_MASK UINT64_C(0x000000000ffff000)          //!< Blend state bit mask

/**
 * Use ALT_GFX_STATE_BLEND_EQUATION(_equation) or ALT_GFX_STATE_BLEND_EQUATION_SEPARATE(_equationRGB, _equationA)
 * helper macros.
 *
 */
#define ALT_GFX_STATE_BLEND_EQUATION_ADD UINT64_C(0x0000000000000000)    //!< Blend add: src + dst.
#define ALT_GFX_STATE_BLEND_EQUATION_SUB UINT64_C(0x0000000010000000)    //!< Blend subtract: src - dst.
#define ALT_GFX_STATE_BLEND_EQUATION_REVSUB UINT64_C(0x0000000020000000) //!< Blend reverse subtract: dst - src.
#define ALT_GFX_STATE_BLEND_EQUATION_MIN UINT64_C(0x0000000030000000)    //!< Blend min: min(src, dst).
#define ALT_GFX_STATE_BLEND_EQUATION_MAX UINT64_C(0x0000000040000000)    //!< Blend max: max(src, dst).
#define ALT_GFX_STATE_BLEND_EQUATION_SHIFT 28                            //!< Blend equation bit shift
#define ALT_GFX_STATE_BLEND_EQUATION_MASK UINT64_C(0x00000003f0000000)   //!< Blend equation bit mask

/**
 * Cull state. When `ALT_GFX_STATE_CULL_*` is not specified culling will be disabled.
 *
 */
#define ALT_GFX_STATE_CULL_CW UINT64_C(0x0000001000000000)   //!< Cull clockwise triangles.
#define ALT_GFX_STATE_CULL_CCW UINT64_C(0x0000002000000000)  //!< Cull counter-clockwise triangles.
#define ALT_GFX_STATE_CULL_SHIFT 36                          //!< Culling mode bit shift
#define ALT_GFX_STATE_CULL_MASK UINT64_C(0x0000003000000000) //!< Culling mode bit mask

/**
 * Alpha reference value.
 *
 */
#define ALT_GFX_STATE_ALPHA_REF_SHIFT 40                          //!< Alpha reference bit shift
#define ALT_GFX_STATE_ALPHA_REF_MASK UINT64_C(0x0000ff0000000000) //!< Alpha reference bit mask
#define ALT_GFX_STATE_ALPHA_REF(v) (((uint64_t)(v) << ALT_GFX_STATE_ALPHA_REF_SHIFT) & ALT_GFX_STATE_ALPHA_REF_MASK)

#define ALT_GFX_STATE_PT_TRISTRIP UINT64_C(0x0001000000000000)  //!< Tristrip.
#define ALT_GFX_STATE_PT_LINES UINT64_C(0x0002000000000000)     //!< Lines.
#define ALT_GFX_STATE_PT_LINESTRIP UINT64_C(0x0003000000000000) //!< Line strip.
#define ALT_GFX_STATE_PT_POINTS UINT64_C(0x0004000000000000)    //!< Points.
#define ALT_GFX_STATE_PT_SHIFT 48                               //!< Primitive type bit shift
#define ALT_GFX_STATE_PT_MASK UINT64_C(0x0007000000000000)      //!< Primitive type bit mask

/**
 * Point size value.
 *
 */
#define ALT_GFX_STATE_POINT_SIZE_SHIFT 52                          //!< Point size bit shift
#define ALT_GFX_STATE_POINT_SIZE_MASK UINT64_C(0x00f0000000000000) //!< Point size bit mask
#define ALT_GFX_STATE_POINT_SIZE(v) (((uint64_t)(v) << ALT_GFX_STATE_POINT_SIZE_SHIFT) & ALT_GFX_STATE_POINT_SIZE_MASK)

/**
 * Enable MSAA write when writing into MSAA frame buffer.
 * This flag is ignored when not writing into MSAA frame buffer.
 *
 */
#define ALT_GFX_STATE_MSAA UINT64_C(0x0100000000000000)                    //!< Enable MSAA rasterization.
#define ALT_GFX_STATE_LINEAA UINT64_C(0x0200000000000000)                  //!< Enable line AA rasterization.
#define ALT_GFX_STATE_CONSERVATIVE_RASTER UINT64_C(0x0400000000000000)     //!< Enable conservative rasterization.
#define ALT_GFX_STATE_NONE UINT64_C(0x0000000000000000)                    //!< No state.
#define ALT_GFX_STATE_FRONT_CCW UINT64_C(0x0000008000000000)               //!< Front counter-clockwise (default is clockwise).
#define ALT_GFX_STATE_BLEND_INDEPENDENT UINT64_C(0x0000000400000000)       //!< Enable blend independent.
#define ALT_GFX_STATE_BLEND_ALPHA_TO_COVERAGE UINT64_C(0x0000000800000000) //!< Enable alpha to coverage.
/// Default state is write to RGB, alpha, and depth with depth test less enabled, with clockwise
/// culling and MSAA (when writing into MSAA frame buffer, otherwise this flag is ignored).
#define ALT_GFX_STATE_DEFAULT (0 | ALT_GFX_STATE_WRITE_RGB | ALT_GFX_STATE_WRITE_A | ALT_GFX_STATE_WRITE_Z | ALT_GFX_STATE_DEPTH_TEST_LESS | ALT_GFX_STATE_CULL_CW | ALT_GFX_STATE_MSAA)

#define ALT_GFX_STATE_MASK UINT64_C(0xffffffffffffffff) //!< State bit mask

/**
 * Do not use!
 *
 */
#define ALT_GFX_STATE_RESERVED_SHIFT 61

#define ALT_GFX_STATE_RESERVED_MASK UINT64_C(0xe000000000000000)

/**
 * Set stencil ref value.
 *
 */
#define ALT_GFX_STENCIL_FUNC_REF_SHIFT 0

#define ALT_GFX_STENCIL_FUNC_REF_MASK UINT32_C(0x000000ff)
#define ALT_GFX_STENCIL_FUNC_REF(v) (((uint32_t)(v) << ALT_GFX_STENCIL_FUNC_REF_SHIFT) & ALT_GFX_STENCIL_FUNC_REF_MASK)

/**
 * Set stencil rmask value.
 *
 */
#define ALT_GFX_STENCIL_FUNC_RMASK_SHIFT 8

#define ALT_GFX_STENCIL_FUNC_RMASK_MASK UINT32_C(0x0000ff00)
#define ALT_GFX_STENCIL_FUNC_RMASK(v) (((uint32_t)(v) << ALT_GFX_STENCIL_FUNC_RMASK_SHIFT) & ALT_GFX_STENCIL_FUNC_RMASK_MASK)

#define ALT_GFX_STENCIL_NONE UINT32_C(0x00000000)
#define ALT_GFX_STENCIL_MASK UINT32_C(0xffffffff)
#define ALT_GFX_STENCIL_DEFAULT UINT32_C(0x00000000)

#define ALT_GFX_STENCIL_TEST_LESS UINT32_C(0x00010000)     //!< Enable stencil test, less.
#define ALT_GFX_STENCIL_TEST_LEQUAL UINT32_C(0x00020000)   //!< Enable stencil test, less or equal.
#define ALT_GFX_STENCIL_TEST_EQUAL UINT32_C(0x00030000)    //!< Enable stencil test, equal.
#define ALT_GFX_STENCIL_TEST_GEQUAL UINT32_C(0x00040000)   //!< Enable stencil test, greater or equal.
#define ALT_GFX_STENCIL_TEST_GREATER UINT32_C(0x00050000)  //!< Enable stencil test, greater.
#define ALT_GFX_STENCIL_TEST_NOTEQUAL UINT32_C(0x00060000) //!< Enable stencil test, not equal.
#define ALT_GFX_STENCIL_TEST_NEVER UINT32_C(0x00070000)    //!< Enable stencil test, never.
#define ALT_GFX_STENCIL_TEST_ALWAYS UINT32_C(0x00080000)   //!< Enable stencil test, always.
#define ALT_GFX_STENCIL_TEST_SHIFT 16                      //!< Stencil test bit shift
#define ALT_GFX_STENCIL_TEST_MASK UINT32_C(0x000f0000)     //!< Stencil test bit mask

#define ALT_GFX_STENCIL_OP_FAIL_S_ZERO UINT32_C(0x00000000)    //!< Zero.
#define ALT_GFX_STENCIL_OP_FAIL_S_KEEP UINT32_C(0x00100000)    //!< Keep.
#define ALT_GFX_STENCIL_OP_FAIL_S_REPLACE UINT32_C(0x00200000) //!< Replace.
#define ALT_GFX_STENCIL_OP_FAIL_S_INCR UINT32_C(0x00300000)    //!< Increment and wrap.
#define ALT_GFX_STENCIL_OP_FAIL_S_INCRSAT UINT32_C(0x00400000) //!< Increment and clamp.
#define ALT_GFX_STENCIL_OP_FAIL_S_DECR UINT32_C(0x00500000)    //!< Decrement and wrap.
#define ALT_GFX_STENCIL_OP_FAIL_S_DECRSAT UINT32_C(0x00600000) //!< Decrement and clamp.
#define ALT_GFX_STENCIL_OP_FAIL_S_INVERT UINT32_C(0x00700000)  //!< Invert.
#define ALT_GFX_STENCIL_OP_FAIL_S_SHIFT 20                     //!< Stencil operation fail bit shift
#define ALT_GFX_STENCIL_OP_FAIL_S_MASK UINT32_C(0x00f00000)    //!< Stencil operation fail bit mask

#define ALT_GFX_STENCIL_OP_FAIL_Z_ZERO UINT32_C(0x00000000)    //!< Zero.
#define ALT_GFX_STENCIL_OP_FAIL_Z_KEEP UINT32_C(0x01000000)    //!< Keep.
#define ALT_GFX_STENCIL_OP_FAIL_Z_REPLACE UINT32_C(0x02000000) //!< Replace.
#define ALT_GFX_STENCIL_OP_FAIL_Z_INCR UINT32_C(0x03000000)    //!< Increment and wrap.
#define ALT_GFX_STENCIL_OP_FAIL_Z_INCRSAT UINT32_C(0x04000000) //!< Increment and clamp.
#define ALT_GFX_STENCIL_OP_FAIL_Z_DECR UINT32_C(0x05000000)    //!< Decrement and wrap.
#define ALT_GFX_STENCIL_OP_FAIL_Z_DECRSAT UINT32_C(0x06000000) //!< Decrement and clamp.
#define ALT_GFX_STENCIL_OP_FAIL_Z_INVERT UINT32_C(0x07000000)  //!< Invert.
#define ALT_GFX_STENCIL_OP_FAIL_Z_SHIFT 24                     //!< Stencil operation depth fail bit shift
#define ALT_GFX_STENCIL_OP_FAIL_Z_MASK UINT32_C(0x0f000000)    //!< Stencil operation depth fail bit mask

#define ALT_GFX_STENCIL_OP_PASS_Z_ZERO UINT32_C(0x00000000)    //!< Zero.
#define ALT_GFX_STENCIL_OP_PASS_Z_KEEP UINT32_C(0x10000000)    //!< Keep.
#define ALT_GFX_STENCIL_OP_PASS_Z_REPLACE UINT32_C(0x20000000) //!< Replace.
#define ALT_GFX_STENCIL_OP_PASS_Z_INCR UINT32_C(0x30000000)    //!< Increment and wrap.
#define ALT_GFX_STENCIL_OP_PASS_Z_INCRSAT UINT32_C(0x40000000) //!< Increment and clamp.
#define ALT_GFX_STENCIL_OP_PASS_Z_DECR UINT32_C(0x50000000)    //!< Decrement and wrap.
#define ALT_GFX_STENCIL_OP_PASS_Z_DECRSAT UINT32_C(0x60000000) //!< Decrement and clamp.
#define ALT_GFX_STENCIL_OP_PASS_Z_INVERT UINT32_C(0x70000000)  //!< Invert.
#define ALT_GFX_STENCIL_OP_PASS_Z_SHIFT 28                     //!< Stencil operation depth pass bit shift
#define ALT_GFX_STENCIL_OP_PASS_Z_MASK UINT32_C(0xf0000000)    //!< Stencil operation depth pass bit mask

#define ALT_GFX_CLEAR_NONE UINT16_C(0x0000)            //!< No clear flags.
#define ALT_GFX_CLEAR_COLOR UINT16_C(0x0001)           //!< Clear color.
#define ALT_GFX_CLEAR_DEPTH UINT16_C(0x0002)           //!< Clear depth.
#define ALT_GFX_CLEAR_STENCIL UINT16_C(0x0004)         //!< Clear stencil.
#define ALT_GFX_CLEAR_DISCARD_COLOR_0 UINT16_C(0x0008) //!< Discard frame buffer attachment 0.
#define ALT_GFX_CLEAR_DISCARD_COLOR_1 UINT16_C(0x0010) //!< Discard frame buffer attachment 1.
#define ALT_GFX_CLEAR_DISCARD_COLOR_2 UINT16_C(0x0020) //!< Discard frame buffer attachment 2.
#define ALT_GFX_CLEAR_DISCARD_COLOR_3 UINT16_C(0x0040) //!< Discard frame buffer attachment 3.
#define ALT_GFX_CLEAR_DISCARD_COLOR_4 UINT16_C(0x0080) //!< Discard frame buffer attachment 4.
#define ALT_GFX_CLEAR_DISCARD_COLOR_5 UINT16_C(0x0100) //!< Discard frame buffer attachment 5.
#define ALT_GFX_CLEAR_DISCARD_COLOR_6 UINT16_C(0x0200) //!< Discard frame buffer attachment 6.
#define ALT_GFX_CLEAR_DISCARD_COLOR_7 UINT16_C(0x0400) //!< Discard frame buffer attachment 7.
#define ALT_GFX_CLEAR_DISCARD_DEPTH UINT16_C(0x0800)   //!< Discard frame buffer depth attachment.
#define ALT_GFX_CLEAR_DISCARD_STENCIL UINT16_C(0x1000) //!< Discard frame buffer stencil attachment.
#define ALT_GFX_CLEAR_DISCARD_COLOR_MASK (0 | ALT_GFX_CLEAR_DISCARD_COLOR_0 | ALT_GFX_CLEAR_DISCARD_COLOR_1 | ALT_GFX_CLEAR_DISCARD_COLOR_2 | ALT_GFX_CLEAR_DISCARD_COLOR_3 | ALT_GFX_CLEAR_DISCARD_COLOR_4 | ALT_GFX_CLEAR_DISCARD_COLOR_5 | ALT_GFX_CLEAR_DISCARD_COLOR_6 | ALT_GFX_CLEAR_DISCARD_COLOR_7)

#define ALT_GFX_CLEAR_DISCARD_MASK (0 | ALT_GFX_CLEAR_DISCARD_COLOR_MASK | ALT_GFX_CLEAR_DISCARD_DEPTH | ALT_GFX_CLEAR_DISCARD_STENCIL)

/**
 * Rendering state discard. When state is preserved in submit, rendering states can be discarded
 * on a finer grain.
 *
 */
#define ALT_GFX_DISCARD_NONE UINT8_C(0x00)           //!< Preserve everything.
#define ALT_GFX_DISCARD_BINDINGS UINT8_C(0x01)       //!< Discard texture sampler and buffer bindings.
#define ALT_GFX_DISCARD_INDEX_BUFFER UINT8_C(0x02)   //!< Discard index buffer.
#define ALT_GFX_DISCARD_INSTANCE_DATA UINT8_C(0x04)  //!< Discard instance data.
#define ALT_GFX_DISCARD_STATE UINT8_C(0x08)          //!< Discard state.
#define ALT_GFX_DISCARD_TRANSFORM UINT8_C(0x10)      //!< Discard transform.
#define ALT_GFX_DISCARD_VERTEX_STREAMS UINT8_C(0x20) //!< Discard vertex streams.
#define ALT_GFX_DISCARD_ALL UINT8_C(0xff)            //!< Discard all states.

#define ALT_GFX_DEBUG_NONE UINT32_C(0x00000000)      //!< No debug.
#define ALT_GFX_DEBUG_WIREFRAME UINT32_C(0x00000001) //!< Enable wireframe for all primitives.

/// Enable infinitely fast hardware test. No draw calls will be submitted to driver.
/// It's useful when profiling to quickly assess bottleneck between CPU and GPU.
#define ALT_GFX_DEBUG_IFH UINT32_C(0x00000002)
#define ALT_GFX_DEBUG_STATS UINT32_C(0x00000004)    //!< Enable statistics display.
#define ALT_GFX_DEBUG_TEXT UINT32_C(0x00000008)     //!< Enable debug text display.
#define ALT_GFX_DEBUG_PROFILER UINT32_C(0x00000010) //!< Enable profiler.

#define ALT_GFX_BUFFER_COMPUTE_FORMAT_8X1 UINT16_C(0x0001)  //!< 1 8-bit value
#define ALT_GFX_BUFFER_COMPUTE_FORMAT_8X2 UINT16_C(0x0002)  //!< 2 8-bit values
#define ALT_GFX_BUFFER_COMPUTE_FORMAT_8X4 UINT16_C(0x0003)  //!< 4 8-bit values
#define ALT_GFX_BUFFER_COMPUTE_FORMAT_16X1 UINT16_C(0x0004) //!< 1 16-bit value
#define ALT_GFX_BUFFER_COMPUTE_FORMAT_16X2 UINT16_C(0x0005) //!< 2 16-bit values
#define ALT_GFX_BUFFER_COMPUTE_FORMAT_16X4 UINT16_C(0x0006) //!< 4 16-bit values
#define ALT_GFX_BUFFER_COMPUTE_FORMAT_32X1 UINT16_C(0x0007) //!< 1 32-bit value
#define ALT_GFX_BUFFER_COMPUTE_FORMAT_32X2 UINT16_C(0x0008) //!< 2 32-bit values
#define ALT_GFX_BUFFER_COMPUTE_FORMAT_32X4 UINT16_C(0x0009) //!< 4 32-bit values
#define ALT_GFX_BUFFER_COMPUTE_FORMAT_SHIFT 0

#define ALT_GFX_BUFFER_COMPUTE_FORMAT_MASK UINT16_C(0x000f)

#define ALT_GFX_BUFFER_COMPUTE_TYPE_INT UINT16_C(0x0010)   //!< Type `int`.
#define ALT_GFX_BUFFER_COMPUTE_TYPE_UINT UINT16_C(0x0020)  //!< Type `uint`.
#define ALT_GFX_BUFFER_COMPUTE_TYPE_FLOAT UINT16_C(0x0030) //!< Type `float`.
#define ALT_GFX_BUFFER_COMPUTE_TYPE_SHIFT 4

#define ALT_GFX_BUFFER_COMPUTE_TYPE_MASK UINT16_C(0x0030)

#define ALT_GFX_BUFFER_NONE UINT16_C(0x0000)
#define ALT_GFX_BUFFER_COMPUTE_READ UINT16_C(0x0100)  //!< Buffer will be read by shader.
#define ALT_GFX_BUFFER_COMPUTE_WRITE UINT16_C(0x0200) //!< Buffer will be used for writing.
#define ALT_GFX_BUFFER_DRAW_INDIRECT UINT16_C(0x0400) //!< Buffer will be used for storing draw indirect commands.
#define ALT_GFX_BUFFER_ALLOW_RESIZE UINT16_C(0x0800)  //!< Allow dynamic index/vertex buffer resize during update.
#define ALT_GFX_BUFFER_INDEX32 UINT16_C(0x1000)       //!< Index buffer contains 32-bit indices.
#define ALT_GFX_BUFFER_COMPUTE_READ_WRITE (0 | ALT_GFX_BUFFER_COMPUTE_READ | ALT_GFX_BUFFER_COMPUTE_WRITE)

#define ALT_GFX_TEXTURE_NONE UINT64_C(0x0000000000000000)
#define ALT_GFX_TEXTURE_MSAA_SAMPLE UINT64_C(0x0000000800000000)   //!< Texture will be used for MSAA sampling.
#define ALT_GFX_TEXTURE_RT UINT64_C(0x0000001000000000)            //!< Render target no MSAA.
#define ALT_GFX_TEXTURE_COMPUTE_WRITE UINT64_C(0x0000100000000000) //!< Texture will be used for compute write.
#define ALT_GFX_TEXTURE_SRGB UINT64_C(0x0000200000000000)          //!< Sample texture as sRGB.
#define ALT_GFX_TEXTURE_BLIT_DST UINT64_C(0x0000400000000000)      //!< Texture will be used as blit destination.
#define ALT_GFX_TEXTURE_READ_BACK UINT64_C(0x0000800000000000)     //!< Texture will be used for read back from GPU.

#define ALT_GFX_TEXTURE_RT_MSAA_X2 UINT64_C(0x0000002000000000)  //!< Render target MSAAx2 mode.
#define ALT_GFX_TEXTURE_RT_MSAA_X4 UINT64_C(0x0000003000000000)  //!< Render target MSAAx4 mode.
#define ALT_GFX_TEXTURE_RT_MSAA_X8 UINT64_C(0x0000004000000000)  //!< Render target MSAAx8 mode.
#define ALT_GFX_TEXTURE_RT_MSAA_X16 UINT64_C(0x0000005000000000) //!< Render target MSAAx16 mode.
#define ALT_GFX_TEXTURE_RT_MSAA_SHIFT 36

#define ALT_GFX_TEXTURE_RT_MSAA_MASK UINT64_C(0x0000007000000000)

#define ALT_GFX_TEXTURE_RT_WRITE_ONLY UINT64_C(0x0000008000000000) //!< Render target will be used for writing
#define ALT_GFX_TEXTURE_RT_SHIFT 36

#define ALT_GFX_TEXTURE_RT_MASK UINT64_C(0x000000f000000000)

/**
 * Sampler flags.
 *
 */
#define ALT_GFX_SAMPLER_U_MIRROR UINT32_C(0x00000001) //!< Wrap U mode: Mirror
#define ALT_GFX_SAMPLER_U_CLAMP UINT32_C(0x00000002)  //!< Wrap U mode: Clamp
#define ALT_GFX_SAMPLER_U_BORDER UINT32_C(0x00000003) //!< Wrap U mode: Border
#define ALT_GFX_SAMPLER_U_SHIFT 0

#define ALT_GFX_SAMPLER_U_MASK UINT32_C(0x00000003)

#define ALT_GFX_SAMPLER_V_MIRROR UINT32_C(0x00000004) //!< Wrap V mode: Mirror
#define ALT_GFX_SAMPLER_V_CLAMP UINT32_C(0x00000008)  //!< Wrap V mode: Clamp
#define ALT_GFX_SAMPLER_V_BORDER UINT32_C(0x0000000c) //!< Wrap V mode: Border
#define ALT_GFX_SAMPLER_V_SHIFT 2

#define ALT_GFX_SAMPLER_V_MASK UINT32_C(0x0000000c)

#define ALT_GFX_SAMPLER_W_MIRROR UINT32_C(0x00000010) //!< Wrap W mode: Mirror
#define ALT_GFX_SAMPLER_W_CLAMP UINT32_C(0x00000020)  //!< Wrap W mode: Clamp
#define ALT_GFX_SAMPLER_W_BORDER UINT32_C(0x00000030) //!< Wrap W mode: Border
#define ALT_GFX_SAMPLER_W_SHIFT 4

#define ALT_GFX_SAMPLER_W_MASK UINT32_C(0x00000030)

#define ALT_GFX_SAMPLER_MIN_POINT UINT32_C(0x00000040)       //!< Min sampling mode: Point
#define ALT_GFX_SAMPLER_MIN_ANISOTROPIC UINT32_C(0x00000080) //!< Min sampling mode: Anisotropic
#define ALT_GFX_SAMPLER_MIN_SHIFT 6

#define ALT_GFX_SAMPLER_MIN_MASK UINT32_C(0x000000c0)

#define ALT_GFX_SAMPLER_MAG_POINT UINT32_C(0x00000100)       //!< Mag sampling mode: Point
#define ALT_GFX_SAMPLER_MAG_ANISOTROPIC UINT32_C(0x00000200) //!< Mag sampling mode: Anisotropic
#define ALT_GFX_SAMPLER_MAG_SHIFT 8

#define ALT_GFX_SAMPLER_MAG_MASK UINT32_C(0x00000300)

#define ALT_GFX_SAMPLER_MIP_POINT UINT32_C(0x00000400) //!< Mip sampling mode: Point
#define ALT_GFX_SAMPLER_MIP_SHIFT 10

#define ALT_GFX_SAMPLER_MIP_MASK UINT32_C(0x00000400)

#define ALT_GFX_SAMPLER_COMPARE_LESS UINT32_C(0x00010000)     //!< Compare when sampling depth texture: less.
#define ALT_GFX_SAMPLER_COMPARE_LEQUAL UINT32_C(0x00020000)   //!< Compare when sampling depth texture: less or equal.
#define ALT_GFX_SAMPLER_COMPARE_EQUAL UINT32_C(0x00030000)    //!< Compare when sampling depth texture: equal.
#define ALT_GFX_SAMPLER_COMPARE_GEQUAL UINT32_C(0x00040000)   //!< Compare when sampling depth texture: greater or equal.
#define ALT_GFX_SAMPLER_COMPARE_GREATER UINT32_C(0x00050000)  //!< Compare when sampling depth texture: greater.
#define ALT_GFX_SAMPLER_COMPARE_NOTEQUAL UINT32_C(0x00060000) //!< Compare when sampling depth texture: not equal.
#define ALT_GFX_SAMPLER_COMPARE_NEVER UINT32_C(0x00070000)    //!< Compare when sampling depth texture: never.
#define ALT_GFX_SAMPLER_COMPARE_ALWAYS UINT32_C(0x00080000)   //!< Compare when sampling depth texture: always.
#define ALT_GFX_SAMPLER_COMPARE_SHIFT 16

#define ALT_GFX_SAMPLER_COMPARE_MASK UINT32_C(0x000f0000)

#define ALT_GFX_SAMPLER_BORDER_COLOR_SHIFT 24

#define ALT_GFX_SAMPLER_BORDER_COLOR_MASK UINT32_C(0x0f000000)
#define ALT_GFX_SAMPLER_BORDER_COLOR(v) (((uint32_t)(v) << ALT_GFX_SAMPLER_BORDER_COLOR_SHIFT) & ALT_GFX_SAMPLER_BORDER_COLOR_MASK)

#define ALT_GFX_SAMPLER_RESERVED_SHIFT 28

#define ALT_GFX_SAMPLER_RESERVED_MASK UINT32_C(0xf0000000)

#define ALT_GFX_SAMPLER_NONE UINT32_C(0x00000000)
#define ALT_GFX_SAMPLER_SAMPLE_STENCIL UINT32_C(0x00100000) //!< Sample stencil instead of depth.
#define ALT_GFX_SAMPLER_POINT (0 | ALT_GFX_SAMPLER_MIN_POINT | ALT_GFX_SAMPLER_MAG_POINT | ALT_GFX_SAMPLER_MIP_POINT)

#define ALT_GFX_SAMPLER_UVW_MIRROR (0 | ALT_GFX_SAMPLER_U_MIRROR | ALT_GFX_SAMPLER_V_MIRROR | ALT_GFX_SAMPLER_W_MIRROR)

#define ALT_GFX_SAMPLER_UVW_CLAMP (0 | ALT_GFX_SAMPLER_U_CLAMP | ALT_GFX_SAMPLER_V_CLAMP | ALT_GFX_SAMPLER_W_CLAMP)

#define ALT_GFX_SAMPLER_UVW_BORDER (0 | ALT_GFX_SAMPLER_U_BORDER | ALT_GFX_SAMPLER_V_BORDER | ALT_GFX_SAMPLER_W_BORDER)

#define ALT_GFX_SAMPLER_BITS_MASK (0 | ALT_GFX_SAMPLER_U_MASK | ALT_GFX_SAMPLER_V_MASK | ALT_GFX_SAMPLER_W_MASK | ALT_GFX_SAMPLER_MIN_MASK | ALT_GFX_SAMPLER_MAG_MASK | ALT_GFX_SAMPLER_MIP_MASK | ALT_GFX_SAMPLER_COMPARE_MASK)

#define ALT_GFX_RESET_MSAA_X2 UINT32_C(0x00000010)  //!< Enable 2x MSAA.
#define ALT_GFX_RESET_MSAA_X4 UINT32_C(0x00000020)  //!< Enable 4x MSAA.
#define ALT_GFX_RESET_MSAA_X8 UINT32_C(0x00000030)  //!< Enable 8x MSAA.
#define ALT_GFX_RESET_MSAA_X16 UINT32_C(0x00000040) //!< Enable 16x MSAA.
#define ALT_GFX_RESET_MSAA_SHIFT 4

#define ALT_GFX_RESET_MSAA_MASK UINT32_C(0x00000070)

#define ALT_GFX_RESET_NONE UINT32_C(0x00000000)               //!< No reset flags.
#define ALT_GFX_RESET_FULLSCREEN UINT32_C(0x00000001)         //!< Not supported yet.
#define ALT_GFX_RESET_VSYNC UINT32_C(0x00000080)              //!< Enable V-Sync.
#define ALT_GFX_RESET_MAXANISOTROPY UINT32_C(0x00000100)      //!< Turn on/off max anisotropy.
#define ALT_GFX_RESET_CAPTURE UINT32_C(0x00000200)            //!< Begin screen capture.
#define ALT_GFX_RESET_FLUSH_AFTER_RENDER UINT32_C(0x00002000) //!< Flush rendering after submitting to GPU.

/// This flag specifies where flip occurs. Default behaviour is that flip occurs
/// before rendering new frame. This flag only has effect when `ALT_GFX_CONFIG_MULTITHREADED=0`.
#define ALT_GFX_RESET_FLIP_AFTER_RENDER UINT32_C(0x00004000)
#define ALT_GFX_RESET_SRGB_BACKBUFFER UINT32_C(0x00008000) //!< Enable sRGB backbuffer.
#define ALT_GFX_RESET_HDR10 UINT32_C(0x00010000)           //!< Enable HDR10 rendering.
#define ALT_GFX_RESET_HIDPI UINT32_C(0x00020000)           //!< Enable HiDPI rendering.
#define ALT_GFX_RESET_DEPTH_CLAMP UINT32_C(0x00040000)     //!< Enable depth clamp.
#define ALT_GFX_RESET_SUSPEND UINT32_C(0x00080000)         //!< Suspend rendering.

#define ALT_GFX_RESET_FULLSCREEN_SHIFT 0

#define ALT_GFX_RESET_FULLSCREEN_MASK UINT32_C(0x00000001)

#define ALT_GFX_RESET_RESERVED_SHIFT 31                  //!< Internal bit shift
#define ALT_GFX_RESET_RESERVED_MASK UINT32_C(0x80000000) //!< Internal bit mask

#define ALT_GFX_CAPS_ALPHA_TO_COVERAGE UINT64_C(0x0000000000000001)   //!< Alpha to coverage is supported.
#define ALT_GFX_CAPS_BLEND_INDEPENDENT UINT64_C(0x0000000000000002)   //!< Blend independent is supported.
#define ALT_GFX_CAPS_COMPUTE UINT64_C(0x0000000000000004)             //!< Compute shaders are supported.
#define ALT_GFX_CAPS_CONSERVATIVE_RASTER UINT64_C(0x0000000000000008) //!< Conservative rasterization is supported.
#define ALT_GFX_CAPS_DRAW_INDIRECT UINT64_C(0x0000000000000010)       //!< Draw indirect is supported.
#define ALT_GFX_CAPS_FRAGMENT_DEPTH UINT64_C(0x0000000000000020)      //!< Fragment depth is accessible in fragment shader.
#define ALT_GFX_CAPS_FRAGMENT_ORDERING UINT64_C(0x0000000000000040)   //!< Fragment ordering is available in fragment shader.
#define ALT_GFX_CAPS_FRAMEBUFFER_RW UINT64_C(0x0000000000000080)      //!< Read/Write frame buffer attachments are supported.
#define ALT_GFX_CAPS_GRAPHICS_DEBUGGER UINT64_C(0x0000000000000100)   //!< Graphics debugger is present.
#define ALT_GFX_CAPS_RESERVED UINT64_C(0x0000000000000200)
#define ALT_GFX_CAPS_HDR10 UINT64_C(0x0000000000000400)                    //!< HDR10 rendering is supported.
#define ALT_GFX_CAPS_HIDPI UINT64_C(0x0000000000000800)                    //!< HiDPI rendering is supported.
#define ALT_GFX_CAPS_INDEX32 UINT64_C(0x0000000000001000)                  //!< 32-bit indices are supported.
#define ALT_GFX_CAPS_INSTANCING UINT64_C(0x0000000000002000)               //!< Instancing is supported.
#define ALT_GFX_CAPS_OCCLUSION_QUERY UINT64_C(0x0000000000004000)          //!< Occlusion query is supported.
#define ALT_GFX_CAPS_RENDERER_MULTITHREADED UINT64_C(0x0000000000008000)   //!< Renderer is on separate thread.
#define ALT_GFX_CAPS_SWAP_CHAIN UINT64_C(0x0000000000010000)               //!< Multiple windows are supported.
#define ALT_GFX_CAPS_TEXTURE_2D_ARRAY UINT64_C(0x0000000000020000)         //!< 2D texture array is supported.
#define ALT_GFX_CAPS_TEXTURE_3D UINT64_C(0x0000000000040000)               //!< 3D textures are supported.
#define ALT_GFX_CAPS_TEXTURE_BLIT UINT64_C(0x0000000000080000)             //!< Texture blit is supported.
#define ALT_GFX_CAPS_TEXTURE_COMPARE_RESERVED UINT64_C(0x0000000000100000) //!< All texture compare modes are supported.
#define ALT_GFX_CAPS_TEXTURE_COMPARE_LEQUAL UINT64_C(0x0000000000200000)   //!< Texture compare less equal mode is supported.
#define ALT_GFX_CAPS_TEXTURE_CUBE_ARRAY UINT64_C(0x0000000000400000)       //!< Cubemap texture array is supported.
#define ALT_GFX_CAPS_TEXTURE_DIRECT_ACCESS UINT64_C(0x0000000000800000)    //!< CPU direct access to GPU texture memory.
#define ALT_GFX_CAPS_TEXTURE_READ_BACK UINT64_C(0x0000000001000000)        //!< Read-back texture is supported.
#define ALT_GFX_CAPS_VERTEX_ATTRIB_HALF UINT64_C(0x0000000002000000)       //!< Vertex attribute half-float is supported.
#define ALT_GFX_CAPS_VERTEX_ATTRIB_UINT10 UINT64_C(0x0000000004000000)     //!< Vertex attribute 10_10_10_2 is supported.
#define ALT_GFX_CAPS_VERTEX_ID UINT64_C(0x0000000008000000)                //!< Rendering with VertexID only is supported.
/// All texture compare modes are supported.
#define ALT_GFX_CAPS_TEXTURE_COMPARE_ALL (0 | ALT_GFX_CAPS_TEXTURE_COMPARE_RESERVED | ALT_GFX_CAPS_TEXTURE_COMPARE_LEQUAL)

#define ALT_GFX_CAPS_FORMAT_TEXTURE_NONE UINT16_C(0x0000)             //!< Texture format is not supported.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_2D UINT16_C(0x0001)               //!< Texture format is supported.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_2D_SRGB UINT16_C(0x0002)          //!< Texture as sRGB format is supported.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_2D_EMULATED UINT16_C(0x0004)      //!< Texture format is emulated.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_3D UINT16_C(0x0008)               //!< Texture format is supported.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_3D_SRGB UINT16_C(0x0010)          //!< Texture as sRGB format is supported.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_3D_EMULATED UINT16_C(0x0020)      //!< Texture format is emulated.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_CUBE UINT16_C(0x0040)             //!< Texture format is supported.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_CUBE_SRGB UINT16_C(0x0080)        //!< Texture as sRGB format is supported.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_CUBE_EMULATED UINT16_C(0x0100)    //!< Texture format is emulated.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_VERTEX UINT16_C(0x0200)           //!< Texture format can be used from vertex shader.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_IMAGE UINT16_C(0x0400)            //!< Texture format can be used as image from compute shader.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_FRAMEBUFFER UINT16_C(0x0800)      //!< Texture format can be used as frame buffer.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_FRAMEBUFFER_MSAA UINT16_C(0x1000) //!< Texture format can be used as MSAA frame buffer.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_MSAA UINT16_C(0x2000)             //!< Texture can be sampled as MSAA.
#define ALT_GFX_CAPS_FORMAT_TEXTURE_MIP_AUTOGEN UINT16_C(0x4000)      //!< Texture format supports auto-generated mips.

#define ALT_GFX_RESOLVE_NONE UINT8_C(0x00)          //!< No resolve flags.
#define ALT_GFX_RESOLVE_AUTO_GEN_MIPS UINT8_C(0x01) //!< Auto-generate mip maps on resolve.

#define ALT_GFX_PCI_ID_NONE UINT16_C(0x0000)                //!< Autoselect adapter.
#define ALT_GFX_PCI_ID_SOFTWARE_RASTERIZER UINT16_C(0x0001) //!< Software rasterizer.
#define ALT_GFX_PCI_ID_AMD UINT16_C(0x1002)                 //!< AMD adapter.
#define ALT_GFX_PCI_ID_INTEL UINT16_C(0x8086)               //!< Intel adapter.
#define ALT_GFX_PCI_ID_NVIDIA UINT16_C(0x10de)              //!< nVidia adapter.

#define ALT_GFX_CUBE_MAP_POSITIVE_X UINT8_C(0x00) //!< Cubemap +x.
#define ALT_GFX_CUBE_MAP_NEGATIVE_X UINT8_C(0x01) //!< Cubemap -x.
#define ALT_GFX_CUBE_MAP_POSITIVE_Y UINT8_C(0x02) //!< Cubemap +y.
#define ALT_GFX_CUBE_MAP_NEGATIVE_Y UINT8_C(0x03) //!< Cubemap -y.
#define ALT_GFX_CUBE_MAP_POSITIVE_Z UINT8_C(0x04) //!< Cubemap +z.
#define ALT_GFX_CUBE_MAP_NEGATIVE_Z UINT8_C(0x05) //!< Cubemap -z.

/// Blend function separate.
#define ALT_GFX_STATE_BLEND_FUNC_SEPARATE(_srcRGB, _dstRGB, _srcA, _dstA) (UINT64_C(0) | (((uint64_t)(_srcRGB) | ((uint64_t)(_dstRGB) << 4))) | (((uint64_t)(_srcA) | ((uint64_t)(_dstA) << 4)) << 8))

/// Blend equation separate.
#define ALT_GFX_STATE_BLEND_EQUATION_SEPARATE(_equationRGB, _equationA) ((uint64_t)(_equationRGB) | ((uint64_t)(_equationA) << 3))

/// Blend function.
#define ALT_GFX_STATE_BLEND_FUNC(_src, _dst) ALT_GFX_STATE_BLEND_FUNC_SEPARATE(_src, _dst, _src, _dst)

/// Blend equation.
#define ALT_GFX_STATE_BLEND_EQUATION(_equation) ALT_GFX_STATE_BLEND_EQUATION_SEPARATE(_equation, _equation)

/// Utility predefined blend modes.

/// Additive blending.
#define ALT_GFX_STATE_BLEND_ADD (0 | ALT_GFX_STATE_BLEND_FUNC(ALT_GFX_STATE_BLEND_ONE, ALT_GFX_STATE_BLEND_ONE))

/// Alpha blend.
#define ALT_GFX_STATE_BLEND_ALPHA (0 | ALT_GFX_STATE_BLEND_FUNC(ALT_GFX_STATE_BLEND_SRC_ALPHA, ALT_GFX_STATE_BLEND_INV_SRC_ALPHA))

/// Selects darker color of blend.
#define ALT_GFX_STATE_BLEND_DARKEN (0 | ALT_GFX_STATE_BLEND_FUNC(ALT_GFX_STATE_BLEND_ONE, ALT_GFX_STATE_BLEND_ONE) | ALT_GFX_STATE_BLEND_EQUATION(ALT_GFX_STATE_BLEND_EQUATION_MIN))

/// Selects lighter color of blend.
#define ALT_GFX_STATE_BLEND_LIGHTEN (0 | ALT_GFX_STATE_BLEND_FUNC(ALT_GFX_STATE_BLEND_ONE, ALT_GFX_STATE_BLEND_ONE) | ALT_GFX_STATE_BLEND_EQUATION(ALT_GFX_STATE_BLEND_EQUATION_MAX))

/// Multiplies colors.
#define ALT_GFX_STATE_BLEND_MULTIPLY (0 | ALT_GFX_STATE_BLEND_FUNC(ALT_GFX_STATE_BLEND_DST_COLOR, ALT_GFX_STATE_BLEND_ZERO))

/// Opaque pixels will cover the pixels directly below them without any math or algorithm applied to them.
#define ALT_GFX_STATE_BLEND_NORMAL (0 | ALT_GFX_STATE_BLEND_FUNC(ALT_GFX_STATE_BLEND_ONE, ALT_GFX_STATE_BLEND_INV_SRC_ALPHA))

/// Multiplies the inverse of the blend and base colors.
#define ALT_GFX_STATE_BLEND_SCREEN (0 | ALT_GFX_STATE_BLEND_FUNC(ALT_GFX_STATE_BLEND_ONE, ALT_GFX_STATE_BLEND_INV_SRC_COLOR))

/// Decreases the brightness of the base color based on the value of the blend color.
#define ALT_GFX_STATE_BLEND_LINEAR_BURN (0 | ALT_GFX_STATE_BLEND_FUNC(ALT_GFX_STATE_BLEND_DST_COLOR, ALT_GFX_STATE_BLEND_INV_DST_COLOR) | ALT_GFX_STATE_BLEND_EQUATION(ALT_GFX_STATE_BLEND_EQUATION_SUB))

///
#define ALT_GFX_STATE_BLEND_FUNC_RT_x(_src, _dst) (0 | ((uint32_t)((_src) >> ALT_GFX_STATE_BLEND_SHIFT) | ((uint32_t)((_dst) >> ALT_GFX_STATE_BLEND_SHIFT) << 4)))

///
#define ALT_GFX_STATE_BLEND_FUNC_RT_xE(_src, _dst, _equation) (0 | ALT_GFX_STATE_BLEND_FUNC_RT_x(_src, _dst) | ((uint32_t)((_equation) >> ALT_GFX_STATE_BLEND_EQUATION_SHIFT) << 8))

#define ALT_GFX_STATE_BLEND_FUNC_RT_1(_src, _dst) (ALT_GFX_STATE_BLEND_FUNC_RT_x(_src, _dst) << 0)
#define ALT_GFX_STATE_BLEND_FUNC_RT_2(_src, _dst) (ALT_GFX_STATE_BLEND_FUNC_RT_x(_src, _dst) << 11)
#define ALT_GFX_STATE_BLEND_FUNC_RT_3(_src, _dst) (ALT_GFX_STATE_BLEND_FUNC_RT_x(_src, _dst) << 22)

#define ALT_GFX_STATE_BLEND_FUNC_RT_1E(_src, _dst, _equation) (ALT_GFX_STATE_BLEND_FUNC_RT_xE(_src, _dst, _equation) << 0)
#define ALT_GFX_STATE_BLEND_FUNC_RT_2E(_src, _dst, _equation) (ALT_GFX_STATE_BLEND_FUNC_RT_xE(_src, _dst, _equation) << 11)
#define ALT_GFX_STATE_BLEND_FUNC_RT_3E(_src, _dst, _equation) (ALT_GFX_STATE_BLEND_FUNC_RT_xE(_src, _dst, _equation) << 22)

namespace alt
{
    class IGFX
    {
    public:
        /// Fatal error enum.
        ///
        ///
        struct Fatal
        {
            enum Enum
            {
                DebugCheck,
                InvalidShader,
                UnableToInitialize,
                UnableToCreateTexture,
                DeviceLost,

                Count
            };
        };

        /// Renderer backend type enum.
        ///
        ///
        struct RendererType
        {
            /// Renderer types:
            enum Enum
            {
                Noop,       //!< No rendering.
                Direct3D9,  //!< Direct3D 9.0
                Direct3D11, //!< Direct3D 11.0
                Direct3D12, //!< Direct3D 12.0
                Gnm,        //!< GNM
                Metal,      //!< Metal
                Nvn,        //!< NVN
                OpenGLES,   //!< OpenGL ES 2.0+
                OpenGL,     //!< OpenGL 2.1+
                Vulkan,     //!< Vulkan
                WebGPU,     //!< WebGPU

                Count
            };
        };

        /// Access mode enum.
        ///
        ///
        struct Access
        {
            /// Access:
            enum Enum
            {
                Read,      //!< Read
                Write,     //!< Write
                ReadWrite, //!< Read and write

                Count
            };
        };

        /// Vertex attribute enum.
        ///
        ///
        struct Attrib
        {
            /// Corresponds to vertex shader attribute.
            enum Enum
            {
                Position,  //!< a_position
                Normal,    //!< a_normal
                Tangent,   //!< a_tangent
                Bitangent, //!< a_bitangent
                Color0,    //!< a_color0
                Color1,    //!< a_color1
                Color2,    //!< a_color2
                Color3,    //!< a_color3
                Indices,   //!< a_indices
                Weight,    //!< a_weight
                TexCoord0, //!< a_texcoord0
                TexCoord1, //!< a_texcoord1
                TexCoord2, //!< a_texcoord2
                TexCoord3, //!< a_texcoord3
                TexCoord4, //!< a_texcoord4
                TexCoord5, //!< a_texcoord5
                TexCoord6, //!< a_texcoord6
                TexCoord7, //!< a_texcoord7

                Count
            };
        };

        /// Vertex attribute type enum.
        ///
        ///
        struct AttribType
        {
            /// Attribute types:
            enum Enum
            {
                Uint8,  //!< Uint8
                Uint10, //!< Uint10, availability depends on: `ALT_GFX_CAPS_VERTEX_ATTRIB_UINT10`.
                Int16,  //!< Int16
                Half,   //!< Half, availability depends on: `ALT_GFX_CAPS_VERTEX_ATTRIB_HALF`.
                Float,  //!< Float

                Count
            };
        };

        /// Texture format enum.
        ///
        /// Notation:
        ///
        ///       RGBA16S
        ///       ^   ^ ^
        ///       |   | +-- [ ]Unorm
        ///       |   |     [F]loat
        ///       |   |     [S]norm
        ///       |   |     [I]nt
        ///       |   |     [U]int
        ///       |   +---- Number of bits per component
        ///       +-------- Components
        ///
        /// @attention Availability depends on Caps (see: formats).
        ///
        ///
        struct TextureFormat
        {
            /// Texture formats:
            enum Enum
            {
                BC1,      //!< DXT1 R5G6B5A1
                BC2,      //!< DXT3 R5G6B5A4
                BC3,      //!< DXT5 R5G6B5A8
                BC4,      //!< LATC1/ATI1 R8
                BC5,      //!< LATC2/ATI2 RG8
                BC6H,     //!< BC6H RGB16F
                BC7,      //!< BC7 RGB 4-7 bits per color channel, 0-8 bits alpha
                ETC1,     //!< ETC1 RGB8
                ETC2,     //!< ETC2 RGB8
                ETC2A,    //!< ETC2 RGBA8
                ETC2A1,   //!< ETC2 RGB8A1
                PTC12,    //!< PVRTC1 RGB 2BPP
                PTC14,    //!< PVRTC1 RGB 4BPP
                PTC12A,   //!< PVRTC1 RGBA 2BPP
                PTC14A,   //!< PVRTC1 RGBA 4BPP
                PTC22,    //!< PVRTC2 RGBA 2BPP
                PTC24,    //!< PVRTC2 RGBA 4BPP
                ATC,      //!< ATC RGB 4BPP
                ATCE,     //!< ATCE RGBA 8 BPP explicit alpha
                ATCI,     //!< ATCI RGBA 8 BPP interpolated alpha
                ASTC4x4,  //!< ASTC 4x4 8.0 BPP
                ASTC5x5,  //!< ASTC 5x5 5.12 BPP
                ASTC6x6,  //!< ASTC 6x6 3.56 BPP
                ASTC8x5,  //!< ASTC 8x5 3.20 BPP
                ASTC8x6,  //!< ASTC 8x6 2.67 BPP
                ASTC10x5, //!< ASTC 10x5 2.56 BPP

                Unknown, // Compressed formats above.

                R1,
                A8,
                R8,
                R8I,
                R8U,
                R8S,
                R16,
                R16I,
                R16U,
                R16F,
                R16S,
                R32I,
                R32U,
                R32F,
                RG8,
                RG8I,
                RG8U,
                RG8S,
                RG16,
                RG16I,
                RG16U,
                RG16F,
                RG16S,
                RG32I,
                RG32U,
                RG32F,
                RGB8,
                RGB8I,
                RGB8U,
                RGB8S,
                RGB9E5F,
                BGRA8,
                RGBA8,
                RGBA8I,
                RGBA8U,
                RGBA8S,
                RGBA16,
                RGBA16I,
                RGBA16U,
                RGBA16F,
                RGBA16S,
                RGBA32I,
                RGBA32U,
                RGBA32F,
                R5G6B5,
                RGBA4,
                RGB5A1,
                RGB10A2,
                RG11B10F,

                UnknownDepth, // Depth formats below.

                D16,
                D24,
                D24S8,
                D32,
                D16F,
                D24F,
                D32F,
                D0S8,

                Count
            };
        };

        /// Uniform type enum.
        ///
        ///
        struct UniformType
        {
            /// Uniform types:
            enum Enum
            {
                Sampler, //!< Sampler.
                End,     //!< Reserved, do not use.

                Vec4, //!< 4 floats vector.
                Mat3, //!< 3x3 matrix.
                Mat4, //!< 4x4 matrix.

                Count
            };
        };

        /// Backbuffer ratio enum.
        ///
        ///
        struct BackbufferRatio
        {
            /// Backbuffer ratios:
            enum Enum
            {
                Equal,     //!< Equal to backbuffer.
                Half,      //!< One half size of backbuffer.
                Quarter,   //!< One quarter size of backbuffer.
                Eighth,    //!< One eighth size of backbuffer.
                Sixteenth, //!< One sixteenth size of backbuffer.
                Double,    //!< Double size of backbuffer.

                Count
            };
        };

        /// Occlusion query result.
        ///
        ///
        struct OcclusionQueryResult
        {
            /// Occlusion query results:
            enum Enum
            {
                Invisible, //!< Query failed test.
                Visible,   //!< Query passed test.
                NoResult,  //!< Query result is not available yet.

                Count
            };
        };

        /// Primitive topology.
        ///
        ///
        struct Topology
        {
            /// Primitive topology:
            enum Enum
            {
                TriList,   //!< Triangle list.
                TriStrip,  //!< Triangle strip.
                LineList,  //!< Line list.
                LineStrip, //!< Line strip.
                PointList, //!< Point list.

                Count
            };
        };

        /// Topology conversion function.
        ///
        ///
        struct TopologyConvert
        {
            /// Topology conversion functions:
            enum Enum
            {
                TriListFlipWinding,  //!< Flip winding order of triangle list.
                TriStripFlipWinding, //!< Flip winding order of trinagle strip.
                TriListToLineList,   //!< Convert triangle list to line list.
                TriStripToTriList,   //!< Convert triangle strip to triangle list.
                LineStripToLineList, //!< Convert line strip to line list.

                Count
            };
        };

        /// Topology sort order.
        ///
        ///
        struct TopologySort
        {
            /// Topology sort order:
            enum Enum
            {
                DirectionFrontToBackMin, //!<
                DirectionFrontToBackAvg, //!<
                DirectionFrontToBackMax, //!<
                DirectionBackToFrontMin, //!<
                DirectionBackToFrontAvg, //!<
                DirectionBackToFrontMax, //!<
                DistanceFrontToBackMin,  //!<
                DistanceFrontToBackAvg,  //!<
                DistanceFrontToBackMax,  //!<
                DistanceBackToFrontMin,  //!<
                DistanceBackToFrontAvg,  //!<
                DistanceBackToFrontMax,  //!<

                Count
            };
        };

        /// View mode sets draw call sort order.
        ///
        ///
        struct ViewMode
        {
            /// View modes:
            enum Enum
            {
                Default,         //!< Default sort order.
                Sequential,      //!< Sort in the same order in which submit calls were called.
                DepthAscending,  //!< Sort draw call depth in ascending order.
                DepthDescending, //!< Sort draw call depth in descending order.

                Count
            };
        };

        static const uint16_t kInvalidHandle = UINT16_MAX;

        ALT_GFX_HANDLE(DynamicIndexBufferHandle)
        ALT_GFX_HANDLE(DynamicVertexBufferHandle)
        ALT_GFX_HANDLE(FrameBufferHandle)
        ALT_GFX_HANDLE(IndexBufferHandle)
        ALT_GFX_HANDLE(IndirectBufferHandle)
        ALT_GFX_HANDLE(OcclusionQueryHandle)
        ALT_GFX_HANDLE(ProgramHandle)
        ALT_GFX_HANDLE(ShaderHandle)
        ALT_GFX_HANDLE(TextureHandle)
        ALT_GFX_HANDLE(UniformHandle)
        ALT_GFX_HANDLE(VertexBufferHandle)
        ALT_GFX_HANDLE(VertexLayoutHandle)

        /// Callback interface to implement application specific behavior.
        /// Cached items are currently used for OpenGL and Direct3D 12 binary
        /// shaders.
        ///
        /// @remarks
        ///   'fatal' and 'trace' callbacks can be called from any thread. Other
        ///   callbacks are called from the render thread.
        ///
        ///
        struct CallbackI
        {
            virtual ~CallbackI() = 0;

            /// This callback is called on unrecoverable errors.
            /// It's not safe to continue (Exluding _code `Fatal::DebugCheck`),
            /// inform the user and terminate the application.
            ///
            /// @param[in] _filePath File path where fatal message was generated.
            /// @param[in] _line Line where fatal message was generated.
            /// @param[in] _code Fatal error code.
            /// @param[in] _str More information about error.
            ///
            /// @remarks
            ///   Not thread safe and it can be called from any thread.
            ///
            ///
            virtual void fatal(const char *_filePath, uint16_t _line, Fatal::Enum _code, const char *_str) = 0;

            /// Print debug message.
            ///
            /// @param[in] _filePath File path where debug message was generated.
            /// @param[in] _line Line where debug message was generated.
            /// @param[in] _format `printf` style format.
            /// @param[in] _argList Variable arguments list initialized with
            ///   `va_start`.
            ///
            /// @remarks
            ///   Not thread safe and it can be called from any thread.
            ///
            ///
            virtual void traceVargs(const char *_filePath, uint16_t _line, const char *_format, va_list _argList) = 0;

            /// Profiler region begin.
            ///
            /// @param[in] _name Region name, contains dynamic string.
            /// @param[in] _abgr Color of profiler region.
            /// @param[in] _filePath File path where `profilerBegin` was called.
            /// @param[in] _line Line where `profilerBegin` was called.
            ///
            /// @remarks
            ///   Not thread safe and it can be called from any thread.
            ///
            ///
            virtual void profilerBegin(const char *_name, uint32_t _abgr, const char *_filePath, uint16_t _line) = 0;

            /// Profiler region begin with string literal name.
            ///
            /// @param[in] _name Region name, contains string literal.
            /// @param[in] _abgr Color of profiler region.
            /// @param[in] _filePath File path where `profilerBeginLiteral` was called.
            /// @param[in] _line Line where `profilerBeginLiteral` was called.
            ///
            /// @remarks
            ///   Not thread safe and it can be called from any thread.
            ///
            ///
            virtual void profilerBeginLiteral(const char *_name, uint32_t _abgr, const char *_filePath, uint16_t _line) = 0;

            /// Profiler region end.
            ///
            /// @remarks
            ///   Not thread safe and it can be called from any thread.
            ///
            ///
            virtual void profilerEnd() = 0;

            /// Returns the size of a cached item. Returns 0 if no cached item was
            /// found.
            ///
            /// @param[in] _id Cache id.
            /// @returns Number of bytes to read.
            ///
            ///
            virtual uint32_t cacheReadSize(uint64_t _id) = 0;

            /// Read cached item.
            ///
            /// @param[in] _id Cache id.
            /// @param[in] _data Buffer where to read data.
            /// @param[in] _size Size of data to read.
            ///
            /// @returns True if data is read.
            ///
            ///
            virtual bool cacheRead(uint64_t _id, void *_data, uint32_t _size) = 0;

            /// Write cached item.
            ///
            /// @param[in] _id Cache id.
            /// @param[in] _data Data to write.
            /// @param[in] _size Size of data to write.
            ///
            ///
            virtual void cacheWrite(uint64_t _id, const void *_data, uint32_t _size) = 0;

            /// Screenshot captured. Screenshot format is always 4-byte BGRA.
            ///
            /// @param[in] _filePath File path.
            /// @param[in] _width Image width.
            /// @param[in] _height Image height.
            /// @param[in] _pitch Number of bytes to skip between the start of
            ///   each horizontal line of the image.
            /// @param[in] _data Image data.
            /// @param[in] _size Image size.
            /// @param[in] _yflip If true, image origin is bottom left.
            ///
            ///
            virtual void screenShot(const char *_filePath, uint32_t _width, uint32_t _height, uint32_t _pitch, const void *_data, uint32_t _size, bool _yflip) = 0;

            /// Called when a video capture begins.
            ///
            /// @param[in] _width Image width.
            /// @param[in] _height Image height.
            /// @param[in] _pitch Number of bytes to skip between the start of
            ///   each horizontal line of the image.
            /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
            /// @param[in] _yflip If true, image origin is bottom left.
            ///
            ///
            virtual void captureBegin(uint32_t _width, uint32_t _height, uint32_t _pitch, TextureFormat::Enum _format, bool _yflip) = 0;

            /// Called when a video capture ends.
            ///
            ///
            virtual void captureEnd() = 0;

            /// Captured frame.
            ///
            /// @param[in] _data Image data.
            /// @param[in] _size Image size.
            ///
            ///
            virtual void captureFrame(const void *_data, uint32_t _size) = 0;
        };

        /// Backbuffer resolution and reset parameters.
        ///
        ///
        struct Resolution
        {
            Resolution() {}

            TextureFormat::Enum format; //!< Backbuffer format.
            uint32_t width;             //!< Backbuffer width.
            uint32_t height;            //!< Backbuffer height.
            uint32_t reset;             //!< Reset parameters.
            uint8_t numBackBuffers;     //!< Number of back buffers.
            uint8_t maxFrameLatency;    //!< Maximum frame latency.
        };

        /// Memory release callback.
        ///
        /// param[in] _ptr Pointer to allocated data.
        /// param[in] _userData User defined data if needed.
        ///
        ///
        typedef void (*ReleaseFn)(void *_ptr, void *_userData);

        /// Memory must be obtained by calling `IGFX::alloc`, `IGFX::copy`, or `IGFX::makeRef`.
        ///
        /// @attention It is illegal to create this structure on stack and pass it to any bgfx API.
        ///
        ///
        struct Memory
        {
            Memory() = delete;

            uint8_t *data; //!< Pointer to data.
            uint32_t size; //!< Data size.
        };

        /// Renderer capabilities.
        ///
        ///
        struct Caps
        {
            /// Renderer backend type. See: `IGFX::RendererType`
            RendererType::Enum rendererType;

            /// Supported functionality.
            ///
            /// @attention See ALT_GFX_CAPS_* flags at https://bkaradzic.github.io/bgfx/bgfx.html#available-caps
            ///
            uint64_t supported;

            uint16_t vendorId;     //!< Selected GPU vendor PCI id.
            uint16_t deviceId;     //!< Selected GPU device id.
            bool homogeneousDepth; //!< True when NDC depth is in [-1, 1] range, otherwise its [0, 1].
            bool originBottomLeft; //!< True when NDC origin is at bottom left.
            uint8_t numGPUs;       //!< Number of enumerated GPUs.

            /// GPU info.
            ///
            ///
            struct GPU
            {
                uint16_t vendorId; //!< Vendor PCI id. See `ALT_GFX_PCI_ID_*`.
                uint16_t deviceId; //!< Device id.
            };

            GPU gpu[4]; //!< Enumerated GPUs.

            /// Renderer runtime limits.
            ///
            ///
            struct Limits
            {
                uint32_t maxDrawCalls;            //!< Maximum number of draw calls.
                uint32_t maxBlits;                //!< Maximum number of blit calls.
                uint32_t maxTextureSize;          //!< Maximum texture size.
                uint32_t maxTextureLayers;        //!< Maximum texture layers.
                uint32_t maxViews;                //!< Maximum number of views.
                uint32_t maxFrameBuffers;         //!< Maximum number of frame buffer handles.
                uint32_t maxFBAttachments;        //!< Maximum number of frame buffer attachments.
                uint32_t maxPrograms;             //!< Maximum number of program handles.
                uint32_t maxShaders;              //!< Maximum number of shader handles.
                uint32_t maxTextures;             //!< Maximum number of texture handles.
                uint32_t maxTextureSamplers;      //!< Maximum number of texture samplers.
                uint32_t maxComputeBindings;      //!< Maximum number of compute bindings.
                uint32_t maxVertexLayouts;        //!< Maximum number of vertex format layouts.
                uint32_t maxVertexStreams;        //!< Maximum number of vertex streams.
                uint32_t maxIndexBuffers;         //!< Maximum number of index buffer handles.
                uint32_t maxVertexBuffers;        //!< Maximum number of vertex buffer handles.
                uint32_t maxDynamicIndexBuffers;  //!< Maximum number of dynamic index buffer handles.
                uint32_t maxDynamicVertexBuffers; //!< Maximum number of dynamic vertex buffer handles.
                uint32_t maxUniforms;             //!< Maximum number of uniform handles.
                uint32_t maxOcclusionQueries;     //!< Maximum number of occlusion query handles.
                uint32_t maxEncoders;             //!< Maximum number of encoder threads.
                uint32_t minResourceCbSize;       //!< Minimum resource command buffer size.
                uint32_t transientVbSize;         //!< Maximum transient vertex buffer size.
                uint32_t transientIbSize;         //!< Maximum transient index buffer size.
            };

            Limits limits; //!< Renderer runtime limits.

            /// Supported texture format capabilities flags:
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_NONE` - Texture format is not supported.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_2D` - Texture format is supported.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_2D_SRGB` - Texture as sRGB format is supported.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_2D_EMULATED` - Texture format is emulated.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_3D` - Texture format is supported.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_3D_SRGB` - Texture as sRGB format is supported.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_3D_EMULATED` - Texture format is emulated.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_CUBE` - Texture format is supported.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_CUBE_SRGB` - Texture as sRGB format is supported.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_CUBE_EMULATED` - Texture format is emulated.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_VERTEX` - Texture format can be used from vertex shader.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_IMAGE` - Texture format can be used as image from compute
            ///     shader.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_FRAMEBUFFER` - Texture format can be used as frame
            ///     buffer.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_FRAMEBUFFER_MSAA` - Texture format can be used as MSAA
            ///     frame buffer.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_MSAA` - Texture can be sampled as MSAA.
            ///   - `ALT_GFX_CAPS_FORMAT_TEXTURE_MIP_AUTOGEN` - Texture format supports auto-generated
            ///     mips.
            uint16_t formats[TextureFormat::Count];
        };

        /// Transient index buffer.
        ///
        ///
        struct TransientIndexBuffer
        {
            uint8_t *data;            //!< Pointer to data.
            uint32_t size;            //!< Data size.
            uint32_t startIndex;      //!< First index.
            IndexBufferHandle handle; //!< Index buffer handle.
        };

        /// Transient vertex buffer.
        ///
        ///
        struct TransientVertexBuffer
        {
            uint8_t *data;                   //!< Pointer to data.
            uint32_t size;                   //!< Data size.
            uint32_t startVertex;            //!< First vertex.
            uint16_t stride;                 //!< Vertex stride.
            VertexBufferHandle handle;       //!< Vertex buffer handle.
            VertexLayoutHandle layoutHandle; //!< Vertex layout handle.
        };

        /// Instance data buffer info.
        ///
        ///
        struct InstanceDataBuffer
        {
            uint8_t *data;             //!< Pointer to data.
            uint32_t size;             //!< Data size.
            uint32_t offset;           //!< Offset in vertex buffer.
            uint32_t num;              //!< Number of instances.
            uint16_t stride;           //!< Vertex buffer stride.
            VertexBufferHandle handle; //!< Vertex buffer object handle.
        };

        /// Texture info.
        ///
        ///
        struct TextureInfo
        {
            TextureFormat::Enum format; //!< Texture format.
            uint32_t storageSize;       //!< Total amount of bytes required to store texture.
            uint16_t width;             //!< Texture width.
            uint16_t height;            //!< Texture height.
            uint16_t depth;             //!< Texture depth.
            uint16_t numLayers;         //!< Number of layers in texture array.
            uint8_t numMips;            //!< Number of MIP maps.
            uint8_t bitsPerPixel;       //!< Format bits per pixel.
            bool cubeMap;               //!< Texture is cubemap.
        };

        /// Uniform info.
        ///
        ///
        struct UniformInfo
        {
            char name[256];         //!< Uniform name.
            UniformType::Enum type; //!< Uniform type.
            uint16_t num;           //!< Number of elements in array.
        };

        /// Frame buffer texture attachment info.
        ///
        ///
        struct Attachment
        {
            /// Init attachment.
            ///
            /// @param[in] _handle Render target texture handle.
            /// @param[in] _access Access. See `Access::Enum`.
            /// @param[in] _layer Cubemap side or depth layer/slice.
            /// @param[in] _mip Mip level.
            /// @param[in] _resolve Resolve flags. See: `ALT_GFX_RESOLVE_*`
            ///
            void init(TextureHandle _handle, Access::Enum _access = Access::Write, uint16_t _layer = 0, uint16_t _mip = 0, uint8_t _resolve = ALT_GFX_RESOLVE_AUTO_GEN_MIPS)
            {
                alt::ICore::Instance().GetGFX()->AttachmentInit(*this, _handle, _access, _layer, _mip, _resolve);
            }

            Access::Enum access;  //!< Attachement access. See `Access::Enum`.
            TextureHandle handle; //!< Render target texture handle.
            uint16_t mip;         //!< Mip level.
            uint16_t layer;       //!< Cubemap side or depth layer/slice.
            uint8_t resolve;      //!< Resolve flags. See: `ALT_GFX_RESOLVE_*`
        };

        /// Delegate for Attachment::init
        virtual void AttachmentInit(Attachment &instance, TextureHandle _handle, Access::Enum _access = Access::Write, uint16_t _layer = 0, uint16_t _mip = 0, uint8_t _resolve = ALT_GFX_RESOLVE_AUTO_GEN_MIPS) = 0;

        /// Transform data.
        ///
        ///
        struct Transform
        {
            float *data;  //!< Pointer to first 4x4 matrix.
            uint16_t num; //!< Number of matrices.
        };

        ///
        typedef uint16_t ViewId;

        /// View stats.
        ///
        ///
        struct ViewStats
        {
            char name[256];       //!< View name.
            ViewId view;          //!< View id.
            int64_t cpuTimeBegin; //!< CPU (submit) begin time.
            int64_t cpuTimeEnd;   //!< CPU (submit) end time.
            int64_t gpuTimeBegin; //!< GPU begin time.
            int64_t gpuTimeEnd;   //!< GPU end time.
        };

        /// Encoder stats.
        ///
        ///
        struct EncoderStats
        {
            int64_t cpuTimeBegin; //!< Encoder thread CPU submit begin time.
            int64_t cpuTimeEnd;   //!< Encoder thread CPU submit end time.
        };

        /// Renderer statistics data.
        ///
        ///
        /// @remarks All time values are high-resolution timestamps, while
        ///   time frequencies define timestamps-per-second for that hardware.
        struct Stats
        {
            int64_t cpuTimeFrame; //!< CPU time between two `IGFX::frame` calls.
            int64_t cpuTimeBegin; //!< Render thread CPU submit begin time.
            int64_t cpuTimeEnd;   //!< Render thread CPU submit end time.
            int64_t cpuTimerFreq; //!< CPU timer frequency. Timestamps-per-second

            int64_t gpuTimeBegin; //!< GPU frame begin time.
            int64_t gpuTimeEnd;   //!< GPU frame end time.
            int64_t gpuTimerFreq; //!< GPU timer frequency.

            int64_t waitRender; //!< Time spent waiting for render backend thread to finish issuing
                                //!  draw commands to underlying graphics API.
            int64_t waitSubmit; //!< Time spent waiting for submit thread to advance to next frame.

            uint32_t numDraw;       //!< Number of draw calls submitted.
            uint32_t numCompute;    //!< Number of compute calls submitted.
            uint32_t numBlit;       //!< Number of blit calls submitted.
            uint32_t maxGpuLatency; //!< GPU driver latency.

            uint16_t numDynamicIndexBuffers;  //!< Number of used dynamic index buffers.
            uint16_t numDynamicVertexBuffers; //!< Number of used dynamic vertex buffers.
            uint16_t numFrameBuffers;         //!< Number of used frame buffers.
            uint16_t numIndexBuffers;         //!< Number of used index buffers.
            uint16_t numOcclusionQueries;     //!< Number of used occlusion queries.
            uint16_t numPrograms;             //!< Number of used programs.
            uint16_t numShaders;              //!< Number of used shaders.
            uint16_t numTextures;             //!< Number of used textures.
            uint16_t numUniforms;             //!< Number of used uniforms.
            uint16_t numVertexBuffers;        //!< Number of used vertex buffers.
            uint16_t numVertexLayouts;        //!< Number of used vertex layouts.

            int64_t textureMemoryUsed; //!< Estimate of texture memory used.
            int64_t rtMemoryUsed;      //!< Estimate of render target memory used.
            int32_t transientVbUsed;   //!< Amount of transient vertex buffer used.
            int32_t transientIbUsed;   //!< Amount of transient index buffer used.

            uint32_t numPrims[Topology::Count]; //!< Number of primitives rendered.

            int64_t gpuMemoryMax;  //!< Maximum available GPU memory for application.
            int64_t gpuMemoryUsed; //!< Amount of GPU memory used by the application.

            uint16_t width;      //!< Backbuffer width in pixels.
            uint16_t height;     //!< Backbuffer height in pixels.
            uint16_t textWidth;  //!< Debug text width in characters.
            uint16_t textHeight; //!< Debug text height in characters.

            uint16_t numViews;    //!< Number of view stats.
            ViewStats *viewStats; //!< Array of View stats.

            uint8_t numEncoders;        //!< Number of encoders used during frame.
            EncoderStats *encoderStats; //!< Array of encoder stats.
        };

        /// Encoders are used for submitting draw calls from multiple threads. Only one encoder
        /// per thread should be used. Use `IGFX::begin()` to obtain an encoder for a thread.
        ///
        ///
        struct Encoder
        {
            /// Sets a debug marker. This allows you to group
            /// graphics calls together for easy browsing in
            /// graphics debugging tools.
            ///
            ///
            virtual void setMarker(const char *_marker) = 0;

            /// Set render states for draw primitive.
            ///
            /// @param[in] _state State flags. Default state for primitive type is
            ///   triangles. See: `ALT_GFX_STATE_DEFAULT`.
            ///   - `ALT_GFX_STATE_DEPTH_TEST_*` - Depth test function.
            ///   - `ALT_GFX_STATE_BLEND_*` - See remark 1 about ALT_GFX_STATE_BLEND_FUNC.
            ///   - `ALT_GFX_STATE_BLEND_EQUATION_*` - See remark 2.
            ///   - `ALT_GFX_STATE_CULL_*` - Backface culling mode.
            ///   - `ALT_GFX_STATE_WRITE_*` - Enable R, G, B, A or Z write.
            ///   - `ALT_GFX_STATE_MSAA` - Enable hardware multisample antialiasing.
            ///   - `ALT_GFX_STATE_PT_[TRISTRIP/LINES/POINTS]` - Primitive type.
            ///
            /// @param[in] _rgba Sets blend factor used by `ALT_GFX_STATE_BLEND_FACTOR` and
            ///   `ALT_GFX_STATE_BLEND_INV_FACTOR` blend modes.
            ///
            /// @remarks
            ///   1. To setup more complex states use:
            ///      `ALT_GFX_STATE_ALPHA_REF(_ref)`,
            ///      `ALT_GFX_STATE_POINT_SIZE(_size)`,
            ///      `ALT_GFX_STATE_BLEND_FUNC(_src, _dst)`,
            ///      `ALT_GFX_STATE_BLEND_FUNC_SEPARATE(_srcRGB, _dstRGB, _srcA, _dstA)`,
            ///      `ALT_GFX_STATE_BLEND_EQUATION(_equation)`,
            ///      `ALT_GFX_STATE_BLEND_EQUATION_SEPARATE(_equationRGB, _equationA)`
            ///   2. `ALT_GFX_STATE_BLEND_EQUATION_ADD` is set when no other blend
            ///      equation is specified.
            ///
            ///
            virtual void setState(uint64_t _state, uint32_t _rgba = 0) = 0;

            /// Set condition for rendering.
            ///
            /// @param[in] _handle Occlusion query handle.
            /// @param[in] _visible Render if occlusion query is visible.
            ///
            ///
            virtual void setCondition(OcclusionQueryHandle _handle, bool _visible) = 0;

            /// Set stencil test state.
            ///
            /// @param[in] _fstencil Front stencil state.
            /// @param[in] _bstencil Back stencil state. If back is set to `ALT_GFX_STENCIL_NONE`
            ///   _fstencil is applied to both front and back facing primitives.
            ///
            ///
            virtual void setStencil(uint32_t _fstencil, uint32_t _bstencil = ALT_GFX_STENCIL_NONE) = 0;

            /// Set scissor for draw primitive. To scissor for all primitives in
            /// view see `IGFX::setViewScissor`.
            ///
            /// @param[in] _x Position x from the left side of the window.
            /// @param[in] _y Position y from the top of the window.
            /// @param[in] _width Width of scissor region.
            /// @param[in] _height Height of scissor region.
            /// @returns Scissor cache index.
            ///
            ///
            virtual uint16_t setScissor(uint16_t _x, uint16_t _y, uint16_t _width, uint16_t _height) = 0;

            /// Set scissor from cache for draw primitive.
            ///
            /// @param[in] _cache Index in scissor cache.
            ///   Pass UINT16_MAX to have primitive use view scissor instead.
            ///
            ///
            virtual void setScissor(uint16_t _cache = UINT16_MAX) = 0;

            /// Set model matrix for draw primitive. If it is not called, model will
            /// be rendered with identity model matrix.
            ///
            /// @param[in] _mtx Pointer to first matrix in array.
            /// @param[in] _num Number of matrices in array.
            /// @returns Index into matrix cache in case the same model matrix has
            ///   to be used for other draw primitive call.
            ///
            ///
            virtual uint32_t setTransform(const void *_mtx, uint16_t _num = 1) = 0;

            /// Reserve `_num` matrices in internal matrix cache.
            ///
            /// @param[in] _transform Pointer to `Transform` structure.
            /// @param[in] _num Number of matrices.
            /// @returns Index into matrix cache.
            ///
            /// @attention Pointer returned can be modifed until `IGFX::frame` is called.
            ///
            virtual uint32_t allocTransform(Transform *_transform, uint16_t _num) = 0;

            /// Set model matrix from matrix cache for draw primitive.
            ///
            /// @param[in] _cache Index in matrix cache.
            /// @param[in] _num Number of matrices from cache.
            ///
            ///
            virtual void setTransform(uint32_t _cache, uint16_t _num = 1) = 0;

            /// Set shader uniform parameter for draw primitive.
            ///
            /// @param[in] _handle Uniform.
            /// @param[in] _value Pointer to uniform data.
            /// @param[in] _num Number of elements. Passing `UINT16_MAX` will
            ///   use the _num passed on uniform creation.
            ///
            ///
            virtual void setUniform(UniformHandle _handle, const void *_value, uint16_t _num = 1) = 0;

            /// Set index buffer for draw primitive.
            ///
            /// @param[in] _handle Index buffer.
            ///
            ///
            virtual void setIndexBuffer(IndexBufferHandle _handle) = 0;

            /// Set index buffer for draw primitive.
            ///
            /// @param[in] _handle Index buffer.
            /// @param[in] _firstIndex First index to render.
            /// @param[in] _numIndices Number of indices to render.
            ///
            ///
            virtual void setIndexBuffer(IndexBufferHandle _handle, uint32_t _firstIndex, uint32_t _numIndices) = 0;

            /// Set index buffer for draw primitive.
            ///
            /// @param[in] _handle Dynamic index buffer.
            ///
            ///
            virtual void setIndexBuffer(DynamicIndexBufferHandle _handle) = 0;

            /// Set index buffer for draw primitive.
            ///
            /// @param[in] _handle Dynamic index buffer.
            /// @param[in] _firstIndex First index to render.
            /// @param[in] _numIndices Number of indices to render.
            ///
            ///
            virtual void setIndexBuffer(DynamicIndexBufferHandle _handle, uint32_t _firstIndex, uint32_t _numIndices) = 0;

            /// Set index buffer for draw primitive.
            ///
            /// @param[in] _tib Transient index buffer.
            ///
            ///
            virtual void setIndexBuffer(const TransientIndexBuffer *_tib) = 0;

            /// Set index buffer for draw primitive.
            ///
            /// @param[in] _tib Transient index buffer.
            /// @param[in] _firstIndex First index to render.
            /// @param[in] _numIndices Number of indices to render.
            ///
            ///
            virtual void setIndexBuffer(const TransientIndexBuffer *_tib, uint32_t _firstIndex, uint32_t _numIndices) = 0;

            /// Set vertex buffer for draw primitive.
            ///
            /// @param[in] _stream Vertex stream.
            /// @param[in] _handle Vertex buffer.
            ///
            ///
            virtual void setVertexBuffer(uint8_t _stream, VertexBufferHandle _handle) = 0;

            /// Set vertex buffer for draw primitive.
            ///
            /// @param[in] _stream Vertex stream.
            /// @param[in] _handle Vertex buffer.
            /// @param[in] _startVertex First vertex to render.
            /// @param[in] _numVertices Number of vertices to render.
            /// @param[in] _layoutHandle Vertex layout for aliasing vertex buffer. If invalid handle is
            ///   used, vertex layout used for creation of vertex buffer will be used.
            ///
            ///
            virtual void setVertexBuffer(uint8_t _stream, VertexBufferHandle _handle, uint32_t _startVertex, uint32_t _numVertices, VertexLayoutHandle _layoutHandle = ALT_GFX_INVALID_HANDLE) = 0;

            /// Set vertex buffer for draw primitive.
            ///
            /// @param[in] _stream Vertex stream.
            /// @param[in] _handle Dynamic vertex buffer.
            ///
            ///
            virtual void setVertexBuffer(uint8_t _stream, DynamicVertexBufferHandle _handle) = 0;

            /// Set vertex buffer for draw primitive.
            ///
            /// @param[in] _stream Vertex stream.
            /// @param[in] _handle Dynamic vertex buffer.
            /// @param[in] _startVertex First vertex to render.
            /// @param[in] _numVertices Number of vertices to render.
            /// @param[in] _layoutHandle Vertex layout for aliasing vertex buffer. If invalid handle is
            ///   used, vertex layout used for creation of vertex buffer will be used.
            ///
            ///
            virtual void setVertexBuffer(uint8_t _stream, DynamicVertexBufferHandle _handle, uint32_t _startVertex, uint32_t _numVertices, VertexLayoutHandle _layoutHandle = ALT_GFX_INVALID_HANDLE) = 0;

            /// Set vertex buffer for draw primitive.
            ///
            /// @param[in] _stream Vertex stream.
            /// @param[in] _tvb Transient vertex buffer.
            ///
            ///
            virtual void setVertexBuffer(uint8_t _stream, const TransientVertexBuffer *_tvb) = 0;

            /// Set vertex buffer for draw primitive.
            ///
            /// @param[in] _stream Vertex stream.
            /// @param[in] _tvb Transient vertex buffer.
            /// @param[in] _startVertex First vertex to render.
            /// @param[in] _numVertices Number of vertices to render.
            /// @param[in] _layoutHandle Vertex layout for aliasing vertex buffer. If invalid handle is
            ///   used, vertex layout used for creation of vertex buffer will be used.
            ///
            ///
            virtual void setVertexBuffer(uint8_t _stream, const TransientVertexBuffer *_tvb, uint32_t _startVertex, uint32_t _numVertices, VertexLayoutHandle _layoutHandle = ALT_GFX_INVALID_HANDLE) = 0;

            /// Set number of vertices for auto generated vertices use in conjuction
            /// with gl_VertexID.
            ///
            /// @param[in] _numVertices Number of vertices.
            ///
            /// @attention Availability depends on: `ALT_GFX_CAPS_VERTEX_ID`.
            ///
            virtual void setVertexCount(uint32_t _numVertices) = 0;

            /// Set instance data buffer for draw primitive.
            ///
            /// @param[in] _idb Transient instance data buffer.
            ///
            ///
            virtual void setInstanceDataBuffer(const InstanceDataBuffer *_idb) = 0;

            /// Set instance data buffer for draw primitive.
            ///
            /// @param[in] _idb Transient instance data buffer.
            /// @param[in] _start First instance data.
            /// @param[in] _num Number of data instances.
            ///
            ///
            virtual void setInstanceDataBuffer(const InstanceDataBuffer *_idb, uint32_t _start, uint32_t _num) = 0;

            /// Set instance data buffer for draw primitive.
            ///
            /// @param[in] _handle Vertex buffer.
            /// @param[in] _start First instance data.
            /// @param[in] _num Number of data instances.
            ///
            ///
            virtual void setInstanceDataBuffer(VertexBufferHandle _handle, uint32_t _start, uint32_t _num) = 0;

            /// Set instance data buffer for draw primitive.
            ///
            /// @param[in] _handle Vertex buffer.
            /// @param[in] _start First instance data.
            /// @param[in] _num Number of data instances.
            ///
            ///
            virtual void setInstanceDataBuffer(DynamicVertexBufferHandle _handle, uint32_t _start, uint32_t _num) = 0;

            /// Set number of instances for auto generated instances use in conjuction
            /// with gl_InstanceID.
            ///
            /// @param[in] _numInstances Number of instances.
            ///
            /// @attention Availability depends on: `ALT_GFX_CAPS_VERTEX_ID`.
            ///
            virtual void setInstanceCount(uint32_t _numInstances) = 0;

            /// Set texture stage for draw primitive.
            ///
            /// @param[in] _stage Texture unit.
            /// @param[in] _sampler Program sampler.
            /// @param[in] _handle Texture handle.
            /// @param[in] _flags Texture sampling mode. Default value UINT32_MAX uses
            ///   texture sampling settings from the texture.
            ///   - `ALT_GFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap
            ///     mode.
            ///   - `ALT_GFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic
            ///     sampling.
            ///
            ///
            virtual void setTexture(uint8_t _stage, UniformHandle _sampler, TextureHandle _handle, uint32_t _flags = UINT32_MAX) = 0;

            /// Submit an empty primitive for rendering. Uniforms and draw state
            /// will be applied but no geometry will be submitted. Useful in cases
            /// when no other draw/compute primitive is submitted to view, but it's
            /// desired to execute clear view.
            ///
            /// These empty draw calls will sort before ordinary draw calls.
            ///
            /// @param[in] _id View id.
            ///
            ///
            virtual void touch(ViewId _id) = 0;

            /// Submit primitive for rendering.
            ///
            /// @param[in] _id View id.
            /// @param[in] _program Program.
            /// @param[in] _depth Depth for sorting.
            /// @param[in] _flags Discard or preserve states. See `ALT_GFX_DISCARD_*`.
            ///
            ///
            virtual void submit(ViewId _id, ProgramHandle _program, uint32_t _depth = 0, uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

            /// Submit primitive with occlusion query for rendering.
            ///
            /// @param[in] _id View id.
            /// @param[in] _program Program.
            /// @param[in] _occlusionQuery Occlusion query.
            /// @param[in] _depth Depth for sorting.
            /// @param[in] _flags Discard or preserve states. See `ALT_GFX_DISCARD_*`.
            ///
            ///
            virtual void submit(ViewId _id, ProgramHandle _program, OcclusionQueryHandle _occlusionQuery, uint32_t _depth = 0, uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

            /// Submit primitive for rendering with index and instance data info from
            /// indirect buffer.
            ///
            /// @param[in] _id View id.
            /// @param[in] _program Program.
            /// @param[in] _indirectHandle Indirect buffer.
            /// @param[in] _start First element in indirect buffer.
            /// @param[in] _num Number of dispatches.
            /// @param[in] _depth Depth for sorting.
            /// @param[in] _flags Discard or preserve states. See `ALT_GFX_DISCARD_*`.
            ///
            ///
            virtual void submit(ViewId _id, ProgramHandle _program, IndirectBufferHandle _indirectHandle, uint16_t _start = 0, uint16_t _num = 1, uint32_t _depth = 0, uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

            /// Set compute index buffer.
            ///
            /// @param[in] _stage Compute stage.
            /// @param[in] _handle Index buffer handle.
            /// @param[in] _access Buffer access. See `Access::Enum`.
            ///
            ///
            virtual void setBuffer(uint8_t _stage, IndexBufferHandle _handle, Access::Enum _access) = 0;

            /// Set compute vertex buffer.
            ///
            /// @param[in] _stage Compute stage.
            /// @param[in] _handle Vertex buffer handle.
            /// @param[in] _access Buffer access. See `Access::Enum`.
            ///
            ///
            virtual void setBuffer(uint8_t _stage, VertexBufferHandle _handle, Access::Enum _access) = 0;

            /// Set compute dynamic index buffer.
            ///
            /// @param[in] _stage Compute stage.
            /// @param[in] _handle Dynamic index buffer handle.
            /// @param[in] _access Buffer access. See `Access::Enum`.
            ///
            ///
            virtual void setBuffer(uint8_t _stage, DynamicIndexBufferHandle _handle, Access::Enum _access) = 0;

            /// Set compute dynamic vertex buffer.
            ///
            /// @param[in] _stage Compute stage.
            /// @param[in] _handle Dynamic vertex buffer handle.
            /// @param[in] _access Buffer access. See `Access::Enum`.
            ///
            ///
            virtual void setBuffer(uint8_t _stage, DynamicVertexBufferHandle _handle, Access::Enum _access) = 0;

            /// Set compute indirect buffer.
            ///
            /// @param[in] _stage Compute stage.
            /// @param[in] _handle Indirect buffer handle.
            /// @param[in] _access Buffer access. See `Access::Enum`.
            ///
            ///
            virtual void setBuffer(uint8_t _stage, IndirectBufferHandle _handle, Access::Enum _access) = 0;

            /// Set compute image from texture.
            ///
            /// @param[in] _stage Texture unit.
            /// @param[in] _handle Texture handle.
            /// @param[in] _mip Mip level.
            /// @param[in] _access Texture access. See `Access::Enum`.
            /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
            ///
            ///
            virtual void setImage(uint8_t _stage, TextureHandle _handle, uint8_t _mip, Access::Enum _access, TextureFormat::Enum _format = TextureFormat::Count) = 0;

            /// Dispatch compute.
            ///
            /// @param[in] _id View id.
            /// @param[in] _handle Compute program.
            /// @param[in] _numX Number of groups X.
            /// @param[in] _numY Number of groups Y.
            /// @param[in] _numZ Number of groups Z.
            /// @param[in] _flags Discard or preserve states. See `ALT_GFX_DISCARD_*`.
            ///
            ///
            virtual void dispatch(ViewId _id, ProgramHandle _handle, uint32_t _numX = 1, uint32_t _numY = 1, uint32_t _numZ = 1, uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

            /// Dispatch compute indirect.
            ///
            /// @param[in] _id View id.
            /// @param[in] _handle Compute program.
            /// @param[in] _indirectHandle Indirect buffer.
            /// @param[in] _start First element in indirect buffer.
            /// @param[in] _num Number of dispatches.
            /// @param[in] _flags Discard or preserve states. See `ALT_GFX_DISCARD_*`.
            ///
            ///
            virtual void dispatch(ViewId _id, ProgramHandle _handle, IndirectBufferHandle _indirectHandle, uint16_t _start = 0, uint16_t _num = 1, uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

            /// Discard all previously set state for draw or compute call.
            ///
            /// @param[in] _flags Draw/compute states to discard.
            ///
            ///
            virtual void discard(uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

            /// Blit texture 2D region between two 2D textures.
            ///
            /// @param[in] _id View id.
            /// @param[in] _dst Destination texture handle.
            /// @param[in] _dstX Destination texture X position.
            /// @param[in] _dstY Destination texture Y position.
            /// @param[in] _src Source texture handle.
            /// @param[in] _srcX Source texture X position.
            /// @param[in] _srcY Source texture Y position.
            /// @param[in] _width Width of region.
            /// @param[in] _height Height of region.
            ///
            /// @attention Destination texture must be created with `ALT_GFX_TEXTURE_BLIT_DST` flag.
            /// @attention Availability depends on: `ALT_GFX_CAPS_TEXTURE_BLIT`.
            ///
            virtual void blit(ViewId _id, TextureHandle _dst, uint16_t _dstX, uint16_t _dstY, TextureHandle _src, uint16_t _srcX = 0, uint16_t _srcY = 0, uint16_t _width = UINT16_MAX, uint16_t _height = UINT16_MAX) = 0;

            /// Blit texture region between two textures.
            ///
            /// @param[in] _id View id.
            /// @param[in] _dst Destination texture handle.
            /// @param[in] _dstMip Destination texture mip level.
            /// @param[in] _dstX Destination texture X position.
            /// @param[in] _dstY Destination texture Y position.
            /// @param[in] _dstZ If texture is 2D this argument should be 0. If destination texture is cube
            ///   this argument represents destination texture cube face. For 3D texture this argument
            ///   represents destination texture Z position.
            /// @param[in] _src Source texture handle.
            /// @param[in] _srcMip Source texture mip level.
            /// @param[in] _srcX Source texture X position.
            /// @param[in] _srcY Source texture Y position.
            /// @param[in] _srcZ If texture is 2D this argument should be 0. If source texture is cube
            ///   this argument represents source texture cube face. For 3D texture this argument
            ///   represents source texture Z position.
            /// @param[in] _width Width of region.
            /// @param[in] _height Height of region.
            /// @param[in] _depth If texture is 3D this argument represents depth of region, otherwise it's
            ///   unused.
            ///
            /// @attention Destination texture must be created with `ALT_GFX_TEXTURE_BLIT_DST` flag.
            /// @attention Availability depends on: `ALT_GFX_CAPS_TEXTURE_BLIT`.
            ///
            virtual void blit(ViewId _id, TextureHandle _dst, uint8_t _dstMip, uint16_t _dstX, uint16_t _dstY, uint16_t _dstZ, TextureHandle _src, uint8_t _srcMip = 0, uint16_t _srcX = 0, uint16_t _srcY = 0, uint16_t _srcZ = 0, uint16_t _width = UINT16_MAX, uint16_t _height = UINT16_MAX, uint16_t _depth = UINT16_MAX) = 0;
        };

        /// Vertex layout.
        ///
        ///
        struct VertexLayout
        {
            VertexLayout()
            {
                *this = alt::ICore::Instance().GetGFX()->VertexLayoutCreate();
            }

            /// Start VertexLayout.
            ///
            ///
            VertexLayout &begin(RendererType::Enum _renderer = RendererType::Noop)
            {
                return alt::ICore::Instance().GetGFX()->VertexLayoutBegin(*this, _renderer);
            }

            /// End VertexLayout.
            ///
            ///
            void end()
            {
                alt::ICore::Instance().GetGFX()->VertexLayoutEnd(*this);
            }

            /// Add attribute to VertexLayout.
            ///
            /// @param[in] _attrib Attribute semantics. See: `IGFX::Attrib`
            /// @param[in] _num Number of elements 1, 2, 3 or 4.
            /// @param[in] _type Element type.
            /// @param[in] _normalized When using fixed point AttribType (f.e. Uint8)
            ///   value will be normalized for vertex shader usage. When normalized
            ///   is set to true, AttribType::Uint8 value in range 0-255 will be
            ///   in range 0.0-1.0 in vertex shader.
            /// @param[in] _asInt Packaging rule for vertexPack, vertexUnpack, and
            ///   vertexConvert for AttribType::Uint8 and AttribType::Int16.
            ///   Unpacking code must be implemented inside vertex shader.
            ///
            /// @remarks
            ///   Must be called between begin/end.
            ///
            ///
            VertexLayout &add(Attrib::Enum _attrib, uint8_t _num, AttribType::Enum _type, bool _normalized = false, bool _asInt = false)
            {
                return alt::ICore::Instance().GetGFX()->VertexLayoutAdd(*this, _attrib, _num, _type, _normalized, _asInt);
            }

            /// Skip _num bytes in vertex stream.
            ///
            ///
            VertexLayout &skip(uint8_t _num)
            {
                return alt::ICore::Instance().GetGFX()->VertexLayoutSkip(*this, _num);
            }

            /// Decode attribute.
            ///
            ///
            void decode(Attrib::Enum _attrib, uint8_t &_num, AttribType::Enum &_type, bool &_normalized, bool &_asInt) const
            {
                alt::ICore::Instance().GetGFX()->VertexLayoutDecode(*this, _attrib, _num, _type, _normalized, _asInt);
            }

            /// Returns true if VertexLayout contains attribute.
            ///
            ///
            bool has(Attrib::Enum _attrib) const { return UINT16_MAX != m_attributes[_attrib]; }

            /// Returns relative attribute offset from the vertex.
            uint16_t getOffset(Attrib::Enum _attrib) const { return m_offset[_attrib]; }

            /// Returns vertex stride.
            uint16_t getStride() const { return m_stride; }

            /// Returns size of vertex buffer for number of vertices.
            uint32_t getSize(uint32_t _num) const { return _num * m_stride; }

            uint32_t m_hash;
            uint16_t m_stride;
            uint16_t m_offset[Attrib::Count];
            uint16_t m_attributes[Attrib::Count];
        };

        // Delegates for VertexLayout functions
        virtual VertexLayout VertexLayoutCreate() = 0;
        virtual VertexLayout &VertexLayoutBegin(VertexLayout &instance, RendererType::Enum _renderer = RendererType::Noop) = 0;
        virtual void VertexLayoutEnd(VertexLayout &instance) = 0;
        virtual VertexLayout &VertexLayoutAdd(VertexLayout &instance, Attrib::Enum _attrib, uint8_t _num, AttribType::Enum _type, bool _normalized = false, bool _asInt = false) = 0;
        virtual VertexLayout &VertexLayoutSkip(VertexLayout &instance, uint8_t _num) = 0;
        virtual void VertexLayoutDecode(const VertexLayout &instance, Attrib::Enum _attrib, uint8_t &_num, AttribType::Enum &_type, bool &_normalized, bool &_asInt) const = 0;

        /// Pack vertex attribute into vertex stream format.
        ///
        /// @param[in] _input Value to be packed into vertex stream.
        /// @param[in] _inputNormalized True if input value is already normalized.
        /// @param[in] _attr Attribute to pack.
        /// @param[in] _layout Vertex stream layout.
        /// @param[in] _data Destination vertex stream where data will be packed.
        /// @param[in] _index Vertex index that will be modified.
        ///
        ///
        virtual void vertexPack(const float _input[4], bool _inputNormalized, Attrib::Enum _attr, const VertexLayout &_layout, void *_data, uint32_t _index = 0) = 0;

        /// Unpack vertex attribute from vertex stream format.
        ///
        /// @param[out] _output Result of unpacking.
        /// @param[in]  _attr Attribute to unpack.
        /// @param[in]  _layout Vertex stream layout.
        /// @param[in]  _data Source vertex stream from where data will be unpacked.
        /// @param[in]  _index Vertex index that will be unpacked.
        ///
        ///
        virtual void vertexUnpack(float _output[4], Attrib::Enum _attr, const VertexLayout &_layout, const void *_data, uint32_t _index = 0) = 0;

        /// Converts vertex stream data from one vertex stream format to another.
        ///
        /// @param[in] _destLayout Destination vertex stream layout.
        /// @param[in] _destData Destination vertex stream.
        /// @param[in] _srcLayout Source vertex stream layout.
        /// @param[in] _srcData Source vertex stream data.
        /// @param[in] _num Number of vertices to convert from source to destination.
        ///
        ///
        virtual void vertexConvert(const VertexLayout &_destLayout, void *_destData, const VertexLayout &_srcLayout, const void *_srcData, uint32_t _num = 1) = 0;

        /// Weld vertices.
        ///
        /// @param[in] _output Welded vertices remapping table. The size of buffer
        ///   must be the same as number of vertices.
        /// @param[in] _layout Vertex stream layout.
        /// @param[in] _data Vertex stream.
        /// @param[in] _num Number of vertices in vertex stream.
        /// @param[in] _index32 Set to `true` if input indices are 32-bit.
        /// @param[in] _epsilon Error tolerance for vertex position comparison.
        /// @returns Number of unique vertices after vertex welding.
        ///
        ///
        virtual uint32_t weldVertices(void *_output, const VertexLayout &_layout, const void *_data, uint32_t _num, bool _index32, float _epsilon = 0.001f) = 0;

        /// Convert index buffer for use with different primitive topologies.
        ///
        /// @param[in] _conversion Conversion type, see `TopologyConvert::Enum`.
        /// @param[in] _dst Destination index buffer. If this argument is NULL
        ///    function will return number of indices after conversion.
        /// @param[in] _dstSize Destination index buffer in bytes. It must be
        ///    large enough to contain output indices. If destination size is
        ///    insufficient index buffer will be truncated.
        /// @param[in] _indices Source indices.
        /// @param[in] _numIndices Number of input indices.
        /// @param[in] _index32 Set to `true` if input indices are 32-bit.
        ///
        /// @returns Number of output indices after conversion.
        ///
        ///
        virtual uint32_t topologyConvert(TopologyConvert::Enum _conversion, void *_dst, uint32_t _dstSize, const void *_indices, uint32_t _numIndices, bool _index32) = 0;

        /// Sort indices.
        ///
        /// @param[in] _sort Sort order, see `TopologySort::Enum`.
        /// @param[in] _dst Destination index buffer.
        /// @param[in] _dstSize Destination index buffer in bytes. It must be
        ///    large enough to contain output indices. If destination size is
        ///    insufficient index buffer will be truncated.
        virtual /// @param[in] _dir Direction (vector must be normalized).
            /// @param[in] _pos Position.
            /// @param[in] _vertices Pointer to first vertex represented as
            ///    float x, y, z. Must contain at least number of vertices
            ///    referencende by index buffer.
            /// @param[in] _stride Vertex stride.
            /// @param[in] _indices Source indices.
            /// @param[in] _numIndices Number of input indices.
            /// @param[in] _index32 Set to `true` if input indices are 32-bit.
            ///
            ///
            virtual void
            topologySortTriList(TopologySort::Enum _sort, void *_dst, uint32_t _dstSize, const float _dir[3], const float _pos[3], const void *_vertices, uint32_t _stride, const void *_indices, uint32_t _numIndices, bool _index32) = 0;

        /// Returns supported backend API renderers.
        ///
        /// @param[in] _max Maximum number of elements in _enum array.
        /// @param[inout] _enum Array where supported renderers will be written.
        ///
        /// @returns Number of supported renderers.
        ///
        ///
        virtual uint8_t getSupportedRenderers(uint8_t _max = 0, RendererType::Enum *_enum = NULL) = 0;

        /// Returns name of renderer.
        ///
        ///
        virtual const char *getRendererName(RendererType::Enum _type) = 0;

        /// Reset graphic settings and back-buffer size.
        ///
        /// @param[in] _width Back-buffer width.
        /// @param[in] _height Back-buffer height.
        /// @param[in] _flags See: `ALT_GFX_RESET_*` for more info.
        ///   - `ALT_GFX_RESET_NONE` - No reset flags.
        ///   - `ALT_GFX_RESET_FULLSCREEN` - Not supported yet.
        ///   - `ALT_GFX_RESET_MSAA_X[2/4/8/16]` - Enable 2, 4, 8 or 16 x MSAA.
        ///   - `ALT_GFX_RESET_VSYNC` - Enable V-Sync.
        ///   - `ALT_GFX_RESET_MAXANISOTROPY` - Turn on/off max anisotropy.
        ///   - `ALT_GFX_RESET_CAPTURE` - Begin screen capture.
        ///   - `ALT_GFX_RESET_FLUSH_AFTER_RENDER` - Flush rendering after submitting to GPU.
        ///   - `ALT_GFX_RESET_FLIP_AFTER_RENDER` - This flag  specifies where flip
        ///     occurs. Default behavior is that flip occurs before rendering new
        ///     frame. This flag only has effect when `ALT_GFX_CONFIG_MULTITHREADED=0`.
        ///   - `ALT_GFX_RESET_SRGB_BACKBUFFER` - Enable sRGB backbuffer.
        /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
        ///
        /// @attention This call doesn't actually change window size, it just
        ///   resizes back-buffer. Windowing code has to change window size.
        ///
        ///
        virtual void reset(uint32_t _width, uint32_t _height, uint32_t _flags = ALT_GFX_RESET_NONE, TextureFormat::Enum _format = TextureFormat::Count) = 0;

        /// Begin submitting draw calls from thread.
        ///
        /// @param[in] _forThread Explicitly request an encoder for a worker thread.
        ///
        virtual Encoder *begin(bool _forThread = false) = 0;

        /// End submitting draw calls from thread.
        ///
        virtual void end(Encoder *_encoder) = 0;

        /// Advance to next frame. When using multithreaded renderer, this call
        /// just swaps internal buffers, kicks render thread, and returns. In
        /// singlethreaded renderer this call does frame rendering.
        ///
        /// @param[in] _capture Capture frame with graphics debugger.
        ///
        /// @returns Current frame number. This might be used in conjunction with
        ///   double/multi buffering data outside the library and passing it to
        ///   library via `IGFX::makeRef` calls.
        ///
        ///
        virtual uint32_t frame(bool _capture = false) = 0;

        /// Returns current renderer backend API type.
        ///
        /// @remarks
        ///   Library must be initialized.
        ///
        ///
        virtual RendererType::Enum getRendererType() = 0;

        /// Returns renderer capabilities.
        ///
        /// @returns Pointer to static `IGFX::Caps` structure.
        ///
        /// @remarks
        ///   Library must be initialized.
        ///
        ///
        virtual const Caps *getCaps() = 0;

        /// Returns performance counters.
        ///
        /// @attention Pointer returned is valid until `IGFX::frame` is called.
        ///
        virtual const Stats *getStats() = 0;

        /// Allocate buffer to pass to bgfx calls. Data will be freed inside bgfx.
        ///
        /// @param[in] _size Size to allocate.
        ///
        ///
        virtual const Memory *alloc(uint32_t _size) = 0;

        /// Allocate buffer and copy data into it. Data will be freed inside bgfx.
        ///
        /// @param[in] _data Pointer to data to be copied.
        /// @param[in] _size Size of data to be copied.
        ///
        ///
        virtual const Memory *copy(const void *_data, uint32_t _size) = 0;

        /// Make reference to data to pass to bgfx. Unlike `IGFX::alloc`, this call
        /// doesn't allocate memory for data. It just copies the _data pointer. You
        /// can pass `ReleaseFn` function pointer to release this memory after it's
        /// consumed, otherwise you must make sure _data is available for at least 2
        /// `IGFX::frame` calls. `ReleaseFn` function must be able to be called
        /// from any thread.
        ///
        /// @param[in] _data Pointer to data.
        /// @param[in] _size Size of data.
        /// @param[in] _releaseFn Callback function to release memory after use.
        /// @param[in] _userData User data to be passed to callback function.
        ///
        /// @attention Data passed must be available for at least 2 `IGFX::frame` calls.
        ///
        virtual const Memory *makeRef(const void *_data, uint32_t _size, ReleaseFn _releaseFn = NULL, void *_userData = NULL) = 0;

        /// Set debug flags.
        ///
        /// @param[in] _debug Available flags:
        ///   - `ALT_GFX_DEBUG_IFH` - Infinitely fast hardware. When this flag is set
        ///     all rendering calls will be skipped. This is useful when profiling
        ///     to quickly assess potential bottlenecks between CPU and GPU.
        ///   - `ALT_GFX_DEBUG_PROFILER` - Enable profiler.
        ///   - `ALT_GFX_DEBUG_STATS` - Display internal statistics.
        ///   - `ALT_GFX_DEBUG_TEXT` - Display debug text.
        ///   - `ALT_GFX_DEBUG_WIREFRAME` - Wireframe rendering. All rendering
        ///     primitives will be rendered as lines.
        ///
        ///
        virtual void setDebug(uint32_t _debug) = 0;

        /// Clear internal debug text buffer.
        ///
        /// @param[in] _attr Background color.
        /// @param[in] _small Default 8x16 or 8x8 font.
        ///
        ///
        virtual void dbgTextClear(uint8_t _attr = 0, bool _small = false) = 0;

        virtual /// Print into internal debug text character-buffer (VGA-compatible text mode).
            ///
            /// @param[in] _x, _y 2D position from top-left.
            /// @param[in] _attr Color palette. Where top 4-bits represent index of background, and bottom
            virtual ///   4-bits represent foreground color from standard VGA text palette (ANSI escape codes).
            /// @param[in] _format `printf` style format.
            ///
            ///
            virtual void
            dbgTextPrintf(uint16_t _x, uint16_t _y, uint8_t _attr, const char *_format, ...) = 0;

        virtual /// Print into internal debug text character-buffer (VGA-compatible text mode).
            ///
            /// @param[in] _x, _y 2D position from top-left.
            /// @param[in] _attr Color palette. Where top 4-bits represent index of background, and bottom
            virtual ///   4-bits represent foreground color from standard VGA text palette (ANSI escape codes).
            /// @param[in] _format `printf` style format.
            /// @param[in] _argList additional arguments for format string
            ///
            ///
            virtual void
            dbgTextPrintfVargs(uint16_t _x, uint16_t _y, uint8_t _attr, const char *_format, va_list _argList) = 0;

        /// Draw image into internal debug text buffer.
        ///
        /// @param[in] _x, _y 2D position from top-left.
        /// @param[in] _width, _height  Image width and height.
        virtual /// @param[in] _data  Raw image data (character/attribute raw encoding).
            /// @param[in] _pitch Image pitch in bytes.
            ///
            ///
            virtual void
            dbgTextImage(uint16_t _x, uint16_t _y, uint16_t _width, uint16_t _height, const void *_data, uint16_t _pitch) = 0;

        /// Create static index buffer.
        ///
        /// @param[in] _mem Index buffer data.
        /// @param[in] _flags Buffer creation flags.
        ///   - `ALT_GFX_BUFFER_NONE` - No flags.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.
        ///   - `ALT_GFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer
        ///       is created with `ALT_GFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.
        ///   - `ALT_GFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of
        ///       data is passed. If this flag is not specified, and more data is passed on update, the buffer
        ///       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic
        ///       buffers.
        ///   - `ALT_GFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on
        ///       index buffers.
        ///
        ///
        virtual IndexBufferHandle createIndexBuffer(const Memory *_mem, uint16_t _flags = ALT_GFX_BUFFER_NONE) = 0;

        /// Set static index buffer debug name.
        ///
        /// @param[in] _handle Static index buffer handle.
        /// @param[in] _name Static index buffer name.
        virtual /// @param[in] _len Static index buffer name length (if length is INT32_MAX, it's expected
            ///   that _name is zero terminated string.
            ///
            ///
            virtual void
            setName(IndexBufferHandle _handle, const char *_name, int32_t _len = INT32_MAX) = 0;

        /// Destroy static index buffer.
        ///
        /// @param[in] _handle Static index buffer handle.
        ///
        ///
        virtual void destroy(IndexBufferHandle _handle) = 0;

        /// Create vertex layout.
        ///
        ///
        virtual VertexLayoutHandle createVertexLayout(const VertexLayout &_layout) = 0;

        /// Destroy vertex layout.
        ///
        ///
        virtual void destroy(VertexLayoutHandle _handle) = 0;

        /// Create static vertex buffer.
        ///
        /// @param[in] _mem Vertex buffer data.
        /// @param[in] _layout Vertex layout.
        /// @param[in] _flags Buffer creation flags.
        ///   - `ALT_GFX_BUFFER_NONE` - No flags.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.
        ///   - `ALT_GFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer
        ///       is created with `ALT_GFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.
        ///   - `ALT_GFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of
        ///       data is passed. If this flag is not specified, and more data is passed on update, the buffer
        ///       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic
        ///       buffers.
        ///   - `ALT_GFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on
        ///       index buffers.
        /// @returns Static vertex buffer handle.
        ///
        ///
        virtual VertexBufferHandle createVertexBuffer(const Memory *_mem, const VertexLayout &_layout, uint16_t _flags = ALT_GFX_BUFFER_NONE) = 0;

        /// Set static vertex buffer debug name.
        ///
        /// @param[in] _handle Static vertex buffer handle.
        /// @param[in] _name Static vertex buffer name.
        virtual /// @param[in] _len Static vertex buffer name length (if length is INT32_MAX, it's expected
            ///   that _name is zero terminated string.
            ///
            ///
            virtual void
            setName(VertexBufferHandle _handle, const char *_name, int32_t _len = INT32_MAX) = 0;

        /// Destroy static vertex buffer.
        ///
        /// @param[in] _handle Static vertex buffer handle.
        ///
        ///
        virtual void destroy(VertexBufferHandle _handle) = 0;

        /// Create empty dynamic index buffer.
        ///
        /// @param[in] _num Number of indices.
        /// @param[in] _flags Buffer creation flags.
        ///   - `ALT_GFX_BUFFER_NONE` - No flags.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.
        ///   - `ALT_GFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer
        ///       is created with `ALT_GFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.
        ///   - `ALT_GFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of
        ///       data is passed. If this flag is not specified, and more data is passed on update, the buffer
        ///       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic
        ///       buffers.
        ///   - `ALT_GFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on
        ///       index buffers.
        /// @returns Dynamic index buffer handle.
        ///
        ///
        virtual DynamicIndexBufferHandle createDynamicIndexBuffer(uint32_t _num, uint16_t _flags = ALT_GFX_BUFFER_NONE) = 0;

        /// Create dynamic index buffer and initialized it.
        ///
        /// @param[in] _mem Index buffer data.
        /// @param[in] _flags Buffer creation flags.
        ///   - `ALT_GFX_BUFFER_NONE` - No flags.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.
        ///   - `ALT_GFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer
        ///       is created with `ALT_GFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.
        ///   - `ALT_GFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of
        ///       data is passed. If this flag is not specified, and more data is passed on update, the buffer
        ///       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic
        ///       buffers.
        ///   - `ALT_GFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on
        ///       index buffers.
        /// @returns Dynamic index buffer handle.
        ///
        ///
        virtual DynamicIndexBufferHandle createDynamicIndexBuffer(const Memory *_mem, uint16_t _flags = ALT_GFX_BUFFER_NONE) = 0;

        /// Update dynamic index buffer.
        ///
        /// @param[in] _handle Dynamic index buffer handle.
        /// @param[in] _startIndex Start index.
        /// @param[in] _mem Index buffer data.
        ///
        ///
        virtual void update(DynamicIndexBufferHandle _handle, uint32_t _startIndex, const Memory *_mem) = 0;

        /// Destroy dynamic index buffer.
        ///
        /// @param[in] _handle Dynamic index buffer handle.
        ///
        ///
        virtual void destroy(DynamicIndexBufferHandle _handle) = 0;

        /// Create empty dynamic vertex buffer.
        ///
        /// @param[in] _num Number of vertices.
        /// @param[in] _layout Vertex layout.
        /// @param[in] _flags Buffer creation flags.
        ///   - `ALT_GFX_BUFFER_NONE` - No flags.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.
        ///   - `ALT_GFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer
        ///       is created with `ALT_GFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.
        ///   - `ALT_GFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of
        ///       data is passed. If this flag is not specified, and more data is passed on update, the buffer
        ///       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic
        ///       buffers.
        ///   - `ALT_GFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on
        ///       index buffers.
        /// @returns Dynamic vertex buffer handle.
        ///
        ///
        virtual DynamicVertexBufferHandle createDynamicVertexBuffer(uint32_t _num, const VertexLayout &_layout, uint16_t _flags = ALT_GFX_BUFFER_NONE) = 0;

        /// Create dynamic vertex buffer and initialize it.
        ///
        /// @param[in] _mem Vertex buffer data.
        /// @param[in] _layout Vertex layout.
        /// @param[in] _flags Buffer creation flags.
        ///   - `ALT_GFX_BUFFER_NONE` - No flags.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.
        ///   - `ALT_GFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer
        ///       is created with `ALT_GFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.
        ///   - `ALT_GFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.
        ///   - `ALT_GFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of
        ///       data is passed. If this flag is not specified, and more data is passed on update, the buffer
        ///       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic
        ///       buffers.
        ///   - `ALT_GFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on
        ///       index buffers.
        /// @returns Dynamic vertex buffer handle.
        ///
        ///
        virtual DynamicVertexBufferHandle createDynamicVertexBuffer(const Memory *_mem, const VertexLayout &_layout, uint16_t _flags = ALT_GFX_BUFFER_NONE) = 0;

        /// Update dynamic vertex buffer.
        ///
        /// @param[in] _handle Dynamic vertex buffer handle.
        /// @param[in] _startVertex Start vertex.
        /// @param[in] _mem Vertex buffer data.
        ///
        ///
        virtual void update(DynamicVertexBufferHandle _handle, uint32_t _startVertex, const Memory *_mem) = 0;

        /// Destroy dynamic vertex buffer.
        ///
        /// @param[in] _handle Dynamic vertex buffer handle.
        ///
        ///
        virtual void destroy(DynamicVertexBufferHandle _handle) = 0;

        /// Returns number of requested or maximum available indices.
        ///
        /// @param[in] _num Number of required indices.
        ///
        ///
        virtual uint32_t getAvailTransientIndexBuffer(uint32_t _num) = 0;

        /// Returns number of requested or maximum available vertices.
        ///
        /// @param[in] _num Number of required vertices.
        /// @param[in] _layout Vertex layout.
        ///
        ///
        virtual uint32_t getAvailTransientVertexBuffer(uint32_t _num, const VertexLayout &_layout) = 0;

        /// Returns number of requested or maximum available instance buffer slots.
        ///
        /// @param[in] _num Number of required instances.
        /// @param[in] _stride Stride per instance.
        ///
        ///
        virtual uint32_t getAvailInstanceDataBuffer(uint32_t _num, uint16_t _stride) = 0;

        /// Allocate transient index buffer.
        ///
        /// @param[out] _tib TransientIndexBuffer structure is filled and is valid
        ///   for the duration of frame, and it can be reused for multiple draw
        ///   calls.
        /// @param[in] _num Number of indices to allocate.
        ///
        /// @remarks
        ///   Only 16-bit index buffer is supported.
        ///
        ///
        virtual void allocTransientIndexBuffer(TransientIndexBuffer *_tib, uint32_t _num) = 0;

        /// Allocate transient vertex buffer.
        ///
        /// @param[out] _tvb TransientVertexBuffer structure is filled and is valid
        ///   for the duration of frame, and it can be reused for multiple draw
        ///   calls.
        /// @param[in] _num Number of vertices to allocate.
        /// @param[in] _layout Vertex layout.
        ///
        ///
        virtual void allocTransientVertexBuffer(TransientVertexBuffer *_tvb, uint32_t _num, const VertexLayout &_layout) = 0;

        /// Check for required space and allocate transient vertex and index
        /// buffers. If both space requirements are satisfied function returns
        /// true.
        ///
        /// @remarks
        ///   Only 16-bit index buffer is supported.
        ///
        ///
        virtual bool allocTransientBuffers(TransientVertexBuffer *_tvb, const VertexLayout &_layout, uint32_t _numVertices, TransientIndexBuffer *_tib, uint32_t _numIndices) = 0;

        /// Allocate instance data buffer.
        ///
        /// @param[out] _idb InstanceDataBuffer structure is filled and is valid
        ///   for duration of frame, and it can be reused for multiple draw
        ///   calls.
        /// @param[in] _num Number of instances.
        /// @param[in] _stride Instance stride. Must be multiple of 16.
        ///
        ///
        virtual void allocInstanceDataBuffer(InstanceDataBuffer *_idb, uint32_t _num, uint16_t _stride) = 0;

        /// Create draw indirect buffer.
        ///
        /// @param[in] _num Number of indirect calls.
        /// @returns Indirect buffer handle.
        ///
        ///
        virtual IndirectBufferHandle createIndirectBuffer(uint32_t _num) = 0;

        /// Destroy draw indirect buffer.
        ///
        /// @param[in] _handle Indirect buffer handle.
        ///
        ///
        virtual void destroy(IndirectBufferHandle _handle) = 0;

        /// Create shader from memory buffer.
        ///
        ///
        virtual ShaderHandle createShader(const Memory *_mem) = 0;

        /// Returns the number of uniforms and uniform handles used inside a shader.
        ///
        /// @param[in] _handle Shader handle.
        /// @param[in] _uniforms UniformHandle array where data will be stored.
        /// @param[in] _max Maximum capacity of array.
        /// @returns Number of uniforms used by shader.
        ///
        /// @remarks
        ///   Only non-predefined uniforms are returned.
        ///
        ///
        virtual uint16_t getShaderUniforms(ShaderHandle _handle, UniformHandle *_uniforms = NULL, uint16_t _max = 0) = 0;

        /// Set shader debug name.
        ///
        /// @param[in] _handle Shader handle.
        /// @param[in] _name Shader name.
        virtual /// @param[in] _len Shader name length (if length is INT32_MAX, it's expected
            ///   that _name is zero terminated string.
            ///
            ///
            virtual void
            setName(ShaderHandle _handle, const char *_name, int32_t _len = INT32_MAX) = 0;

        /// Destroy shader. Once a shader program is created with _handle,
        /// it is safe to destroy that shader.
        ///
        /// @param[in] _handle Shader handle.
        ///
        ///
        virtual void destroy(ShaderHandle _handle) = 0;

        /// Create program with vertex and fragment shaders.
        ///
        /// @param[in] _vsh Vertex shader.
        /// @param[in] _fsh Fragment shader.
        /// @param[in] _destroyShaders If true, shaders will be destroyed when
        ///   program is destroyed.
        /// @returns Program handle if vertex shader output and fragment shader
        ///   input are matching, otherwise returns invalid program handle.
        ///
        ///
        virtual ProgramHandle createProgram(ShaderHandle _vsh, ShaderHandle _fsh, bool _destroyShaders = false) = 0;

        /// Create program with compute shader.
        ///
        /// @param[in] _csh Compute shader.
        /// @param[in] _destroyShader If true, shader will be destroyed when
        ///   program is destroyed.
        /// @returns Program handle.
        ///
        ///
        virtual ProgramHandle createProgram(ShaderHandle _csh, bool _destroyShader = false) = 0;

        /// Destroy program.
        ///
        /// @param[in] _handle Program handle.
        ///
        ///
        virtual void destroy(ProgramHandle _handle) = 0;

        /// Validate texture parameters.
        ///
        /// @param[in] _depth Depth dimension of volume texture.
        /// @param[in] _cubeMap Indicates that texture contains cubemap.
        /// @param[in] _numLayers Number of layers in texture array.
        /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
        /// @param[in] _flags Texture flags. See `ALT_GFX_TEXTURE_*`.
        /// @returns True if texture can be successfully created.
        ///
        ///
        virtual bool isTextureValid(uint16_t _depth, bool _cubeMap, uint16_t _numLayers, TextureFormat::Enum _format, uint64_t _flags) = 0;

        /// Calculate amount of memory required for texture.
        ///
        /// @param[out] _info Resulting texture info structure. See: `TextureInfo`.
        /// @param[in] _width Width.
        /// @param[in] _height Height.
        /// @param[in] _depth Depth dimension of volume texture.
        /// @param[in] _cubeMap Indicates that texture contains cubemap.
        /// @param[in] _hasMips Indicates that texture contains full mip-map chain.
        /// @param[in] _numLayers Number of layers in texture array.
        /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
        ///
        ///
        virtual void calcTextureSize(TextureInfo &_info, uint16_t _width, uint16_t _height, uint16_t _depth, bool _cubeMap, bool _hasMips, uint16_t _numLayers, TextureFormat::Enum _format) = 0;

        /// Create texture from memory buffer.
        ///
        /// @param[in] _mem DDS, KTX or PVR texture data.
        virtual /// @param[in] _flags Texture creation (see `ALT_GFX_TEXTURE_*`.), and sampler (see `ALT_GFX_SAMPLER_*`)
            ///   flags. Default texture sampling mode is linear, and wrap mode is repeat.
            ///   - `ALT_GFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap
            ///     mode.
            ///   - `ALT_GFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic
            ///     sampling.
            ///
            /// @param[in] _skip Skip top level mips when parsing texture.
            /// @param[out] _info When non-`NULL` is specified it returns parsed texture information.
            /// @returns Texture handle.
            ///
            ///
            virtual TextureHandle
            createTexture(const Memory *_mem, uint64_t _flags = ALT_GFX_TEXTURE_NONE | ALT_GFX_SAMPLER_NONE, uint8_t _skip = 0, TextureInfo *_info = NULL) = 0;

        /// Create 2D texture.
        ///
        /// @param[in] _width Width.
        /// @param[in] _height Height.
        /// @param[in] _hasMips Indicates that texture contains full mip-map chain.
        /// @param[in] _numLayers Number of layers in texture array. Must be 1 if caps
        ///   `ALT_GFX_CAPS_TEXTURE_2D_ARRAY` flag is not set.
        /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
        virtual /// @param[in] _flags Texture creation (see `ALT_GFX_TEXTURE_*`.), and sampler (see `ALT_GFX_SAMPLER_*`)
            ///   flags. Default texture sampling mode is linear, and wrap mode is repeat.
            ///   - `ALT_GFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap
            ///     mode.
            ///   - `ALT_GFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic
            ///     sampling.
            ///
            /// @param[in] _mem Texture data. If `_mem` is non-NULL, created texture will be immutable. If
            ///   `_mem` is NULL content of the texture is uninitialized. When `_numLayers` is more than
            ///   1, expected memory layout is texture and all mips together for each array element.
            ///
            ///
            virtual TextureHandle
            createTexture2D(uint16_t _width, uint16_t _height, bool _hasMips, uint16_t _numLayers, TextureFormat::Enum _format, uint64_t _flags = ALT_GFX_TEXTURE_NONE | ALT_GFX_SAMPLER_NONE, const Memory *_mem = NULL) = 0;

        /// Create texture with size based on backbuffer ratio. Texture will maintain ratio
        /// if back buffer resolution changes.
        ///
        /// @param[in] _ratio Frame buffer size in respect to back-buffer size. See:
        ///   `BackbufferRatio::Enum`.
        /// @param[in] _hasMips Indicates that texture contains full mip-map chain.
        /// @param[in] _numLayers Number of layers in texture array. Must be 1 if caps
        ///   `ALT_GFX_CAPS_TEXTURE_2D_ARRAY` flag is not set.
        /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
        virtual /// @param[in] _flags Texture creation (see `ALT_GFX_TEXTURE_*`.), and sampler (see `ALT_GFX_SAMPLER_*`)
            ///   flags. Default texture sampling mode is linear, and wrap mode is repeat.
            ///   - `ALT_GFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap
            ///     mode.
            ///   - `ALT_GFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic
            ///     sampling.
            ///
            ///
            virtual TextureHandle
            createTexture2D(BackbufferRatio::Enum _ratio, bool _hasMips, uint16_t _numLayers, TextureFormat::Enum _format, uint64_t _flags = ALT_GFX_TEXTURE_NONE | ALT_GFX_SAMPLER_NONE) = 0;

        /// Create 3D texture.
        ///
        /// @param[in] _width Width.
        /// @param[in] _height Height.
        /// @param[in] _depth Depth.
        /// @param[in] _hasMips Indicates that texture contains full mip-map chain.
        /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
        virtual /// @param[in] _flags Texture creation (see `ALT_GFX_TEXTURE_*`.), and sampler (see `ALT_GFX_SAMPLER_*`)
            ///   flags. Default texture sampling mode is linear, and wrap mode is repeat.
            ///   - `ALT_GFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap
            ///     mode.
            ///   - `ALT_GFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic
            ///     sampling.
            ///
            /// @param[in] _mem Texture data. If `_mem` is non-NULL, created texture will be immutable. If
            ///   `_mem` is NULL content of the texture is uninitialized.
            ///
            ///
            virtual TextureHandle
            createTexture3D(uint16_t _width, uint16_t _height, uint16_t _depth, bool _hasMips, TextureFormat::Enum _format, uint64_t _flags = ALT_GFX_TEXTURE_NONE | ALT_GFX_SAMPLER_NONE, const Memory *_mem = NULL) = 0;

        /// Create Cube texture.
        ///
        /// @param[in] _size Cube side size.
        /// @param[in] _hasMips Indicates that texture contains full mip-map chain.
        /// @param[in] _numLayers Number of layers in texture array. Must be 1 if caps
        ///   `ALT_GFX_CAPS_TEXTURE_CUBE_ARRAY` flag is not set.
        /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
        virtual /// @param[in] _flags Texture creation (see `ALT_GFX_TEXTURE_*`.), and sampler (see `ALT_GFX_SAMPLER_*`)
            ///   flags. Default texture sampling mode is linear, and wrap mode is repeat.
            ///   - `ALT_GFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap
            ///     mode.
            ///   - `ALT_GFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic
            ///     sampling.
            ///
            /// @param[in] _mem Texture data. If `_mem` is non-NULL, created texture will be immutable. If
            ///   `_mem` is NULL content of the texture is uninitialized. When `_numLayers` is more than
            ///   1, expected memory layout is texture and all mips together for each array element.
            ///
            ///
            virtual TextureHandle
            createTextureCube(uint16_t _size, bool _hasMips, uint16_t _numLayers, TextureFormat::Enum _format, uint64_t _flags = ALT_GFX_TEXTURE_NONE | ALT_GFX_SAMPLER_NONE, const Memory *_mem = NULL) = 0;

        /// Update 2D texture.
        ///
        /// @param[in] _handle Texture handle.
        /// @param[in] _layer Layers in texture array.
        /// @param[in] _mip Mip level.
        /// @param[in] _x X offset in texture.
        /// @param[in] _y Y offset in texture.
        /// @param[in] _width Width of texture block.
        /// @param[in] _height Height of texture block.
        /// @param[in] _mem Texture update data.
        virtual /// @param[in] _pitch Pitch of input image (bytes). When _pitch is set to
            ///   UINT16_MAX, it will be calculated internally based on _width.
            ///
            /// @attention It's valid to update only mutable texture. See `IGFX::createTexture2D` for more info.
            ///
            ///
            virtual void
            updateTexture2D(TextureHandle _handle, uint16_t _layer, uint8_t _mip, uint16_t _x, uint16_t _y, uint16_t _width, uint16_t _height, const Memory *_mem, uint16_t _pitch = UINT16_MAX) = 0;

        /// Update 3D texture.
        ///
        /// @param[in] _handle Texture handle.
        /// @param[in] _mip Mip level.
        /// @param[in] _x X offset in texture.
        /// @param[in] _y Y offset in texture.
        /// @param[in] _z Z offset in texture.
        /// @param[in] _width Width of texture block.
        /// @param[in] _height Height of texture block.
        /// @param[in] _depth Depth of texture block.
        /// @param[in] _mem Texture update data.
        ///
        /// @attention It's valid to update only mutable texture. See `IGFX::createTexture3D` for more info.
        ///
        ///
        virtual void updateTexture3D(TextureHandle _handle, uint8_t _mip, uint16_t _x, uint16_t _y, uint16_t _z, uint16_t _width, uint16_t _height, uint16_t _depth, const Memory *_mem) = 0;

        /// Update Cube texture.
        ///
        /// @param[in] _handle Texture handle.
        /// @param[in] _layer Layers in texture array.
        /// @param[in] _side Cubemap side `ALT_GFX_CUBE_MAP_<POSITIVE or NEGATIVE>_<X, Y or Z>`,
        ///   where 0 is +X, 1 is -X, 2 is +Y, 3 is -Y, 4 is +Z, and 5 is -Z.
        ///
        ///                  +----------+
        ///                  |-z       2|
        ///                  | ^  +y    |
        ///                  | |        |    Unfolded cube:
        ///                  | +---->+x |
        ///       +----------+----------+----------+----------+
        ///       |+y       1|+y       4|+y       0|+y       5|
        ///       | ^  -x    | ^  +z    | ^  +x    | ^  -z    |
        ///       | |        | |        | |        | |        |
        ///       | +---->+z | +---->+x | +---->-z | +---->-x |
        ///       +----------+----------+----------+----------+
        ///                  |+z       3|
        ///                  | ^  -y    |
        ///                  | |        |
        ///                  | +---->+x |
        ///                  +----------+
        ///
        /// @param[in] _mip Mip level.
        /// @param[in] _x X offset in texture.
        /// @param[in] _y Y offset in texture.
        /// @param[in] _width Width of texture block.
        /// @param[in] _height Height of texture block.
        /// @param[in] _mem Texture update data.
        virtual /// @param[in] _pitch Pitch of input image (bytes). When _pitch is set to
            ///   UINT16_MAX, it will be calculated internally based on _width.
            ///
            /// @attention It's valid to update only mutable texture. See `IGFX::createTextureCube` for more info.
            ///
            ///
            virtual void
            updateTextureCube(TextureHandle _handle, uint16_t _layer, uint8_t _side, uint8_t _mip, uint16_t _x, uint16_t _y, uint16_t _width, uint16_t _height, const Memory *_mem, uint16_t _pitch = UINT16_MAX) = 0;

        /// Read back texture content.
        ///
        /// @param[in] _handle Texture handle.
        /// @param[in] _data Destination buffer.
        /// @param[in] _mip Mip level.
        ///
        /// @returns Frame number when the result will be available. See: `IGFX::frame`.
        ///
        /// @attention Texture must be created with `ALT_GFX_TEXTURE_READ_BACK` flag.
        /// @attention Availability depends on: `ALT_GFX_CAPS_TEXTURE_READ_BACK`.
        ///
        virtual uint32_t readTexture(TextureHandle _handle, void *_data, uint8_t _mip = 0) = 0;

        /// Set texture debug name.
        ///
        /// @param[in] _handle Texture handle.
        /// @param[in] _name Texture name.
        virtual /// @param[in] _len Texture name length (if length is INT32_MAX, it's expected
            ///   that _name is zero terminated string.
            ///
            ///
            virtual void
            setName(TextureHandle _handle, const char *_name, int32_t _len = INT32_MAX) = 0;

        /// Returns texture direct access pointer.
        ///
        /// @param[in] _handle Texture handle.
        ///
        /// @returns Pointer to texture memory. If returned pointer is `NULL` direct access
        ///   is not available for this texture. If pointer is `UINTPTR_MAX` sentinel value
        ///   it means texture is pending creation. Pointer returned can be cached and it
        ///   will be valid until texture is destroyed.
        ///
        /// @attention Availability depends on: `ALT_GFX_CAPS_TEXTURE_DIRECT_ACCESS`. This feature
        virtual ///   is available on GPUs that have unified memory architecture (UMA) support.
            ///
            ///
            virtual void *
            getDirectAccessPtr(TextureHandle _handle) = 0;

        /// Destroy texture.
        ///
        /// @param[in] _handle Texture handle.
        ///
        ///
        virtual void destroy(TextureHandle _handle) = 0;

        virtual /// Create frame buffer (simple).
            ///
            /// @param[in] _width Texture width.
            /// @param[in] _height Texture height.
            /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
            /// @param[in] _textureFlags Default texture sampling mode is linear, and wrap mode
            ///   is repeat.
            ///   - `ALT_GFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap
            ///     mode.
            ///   - `ALT_GFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic
            ///     sampling.
            ///
            /// @returns Handle to frame buffer object.
            ///
            ///
            virtual FrameBufferHandle
            createFrameBuffer(uint16_t _width, uint16_t _height, TextureFormat::Enum _format, uint64_t _textureFlags = ALT_GFX_SAMPLER_U_CLAMP | ALT_GFX_SAMPLER_V_CLAMP) = 0;

        /// Create frame buffer with size based on backbuffer ratio. Frame buffer will maintain ratio
        /// if back buffer resolution changes.
        ///
        /// @param[in] _ratio Frame buffer size in respect to back-buffer size. See:
        ///   `BackbufferRatio::Enum`.
        /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
        /// @param[in] _textureFlags Default texture sampling mode is linear, and wrap mode
        ///   is repeat.
        ///   - `ALT_GFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap
        ///     mode.
        ///   - `ALT_GFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic
        ///     sampling.
        ///
        /// @returns Handle to frame buffer object.
        ///
        ///
        virtual FrameBufferHandle createFrameBuffer(BackbufferRatio::Enum _ratio, TextureFormat::Enum _format, uint64_t _textureFlags = ALT_GFX_SAMPLER_U_CLAMP | ALT_GFX_SAMPLER_V_CLAMP) = 0;

        virtual /// Create MRT frame buffer from texture handles (simple).
            ///
            /// @param[in] _num Number of texture attachments.
            /// @param[in] _handles Texture attachments.
            /// @param[in] _destroyTextures If true, textures will be destroyed when
            ///   frame buffer is destroyed.
            ///
            /// @returns Handle to frame buffer object.
            ///
            ///
            virtual FrameBufferHandle
            createFrameBuffer(uint8_t _num, const TextureHandle *_handles, bool _destroyTextures = false) = 0;

        /// Create MRT frame buffer from texture handles with specific layer and
        /// mip level.
        ///
        /// @param[in] _num Number of texture attachments.
        /// @param[in] _attachment Attachment texture info. See: `IGFX::Attachment`.
        /// @param[in] _destroyTextures If true, textures will be destroyed when
        ///   frame buffer is destroyed.
        ///
        /// @returns Handle to frame buffer object.
        ///
        ///
        virtual FrameBufferHandle createFrameBuffer(uint8_t _num, const Attachment *_attachment, bool _destroyTextures = false) = 0;

        /// Create frame buffer for multiple window rendering.
        ///
        /// @param[in] _nwh OS' target native window handle.
        /// @param[in] _width Window back buffer width.
        /// @param[in] _height Window back buffer height.
        /// @param[in] _format Window back buffer color format.
        /// @param[in] _depthFormat Window back buffer depth format.
        ///
        /// @returns Handle to frame buffer object.
        ///
        /// @remarks
        ///   Frame buffer cannot be used for sampling.
        ///
        ///
        virtual FrameBufferHandle createFrameBuffer(void *_nwh, uint16_t _width, uint16_t _height, TextureFormat::Enum _format = TextureFormat::Count, TextureFormat::Enum _depthFormat = TextureFormat::Count) = 0;

        /// Set frame buffer debug name.
        ///
        /// @param[in] _handle frame buffer handle.
        /// @param[in] _name frame buffer name.
        virtual /// @param[in] _len frame buffer name length (if length is INT32_MAX, it's expected
            ///   that _name is zero terminated string.
            ///
            ///
            virtual void
            setName(FrameBufferHandle _handle, const char *_name, int32_t _len = INT32_MAX) = 0;

        /// Obtain texture handle of frame buffer attachment.
        ///
        /// @param[in] _handle Frame buffer handle.
        /// @param[in] _attachment Frame buffer attachment index.
        ///
        /// @returns Returns invalid texture handle if attachment index is not
        ///   correct, or frame buffer is created with native window handle.
        ///
        ///
        virtual TextureHandle getTexture(FrameBufferHandle _handle, uint8_t _attachment = 0) = 0;

        /// Destroy frame buffer.
        ///
        /// @param[in] _handle Frame buffer handle.
        ///
        ///
        virtual void destroy(FrameBufferHandle _handle) = 0;

        /// Create shader uniform parameter.
        ///
        /// @param[in] _name Uniform name in shader.
        virtual /// @param[in] _type Type of uniform (See: `IGFX::UniformType`).
            /// @param[in] _num Number of elements in array.
            ///
            /// @returns Handle to uniform object.
            ///
            /// @remarks
            ///   1. Uniform names are unique. It's valid to call `IGFX::createUniform`
            ///      multiple times with the same uniform name. The library will always
            ///      return the same handle, but the handle reference count will be
            ///      incremented. This means that the same number of `IGFX::destroyUniform`
            ///      must be called to properly destroy the uniform.
            ///
            virtual ///   2. Predefined uniforms (declared in `ALT_GFX_shader.sh`):
            virtual ///      - `u_viewRect vec4(x, y, width, height)` - view rectangle for current
            ///        view, in pixels.
            virtual ///      - `u_viewTexel vec4(1.0/width, 1.0/height, undef, undef)` - inverse
            ///        width and height
            ///      - `u_view mat4` - view matrix
            ///      - `u_invView mat4` - inverted view matrix
            ///      - `u_proj mat4` - projection matrix
            ///      - `u_invProj mat4` - inverted projection matrix
            ///      - `u_viewProj mat4` - concatenated view projection matrix
            ///      - `u_invViewProj mat4` - concatenated inverted view projection matrix
            ///      - `u_model mat4[ALT_GFX_CONFIG_MAX_BONES]` - array of model matrices.
            ///      - `u_modelView mat4` - concatenated model view matrix, only first
            ///        model matrix from array is used.
            ///      - `u_modelViewProj mat4` - concatenated model view projection matrix.
            ///      - `u_alphaRef float` - alpha reference value for alpha test.
            ///
            ///
            virtual UniformHandle
            createUniform(const char *_name, UniformType::Enum _type, uint16_t _num = 1) = 0;

        /// Retrieve uniform info.
        ///
        /// @param[in] _handle Handle to uniform object.
        /// @param[out] _info Uniform info.
        ///
        ///
        virtual void getUniformInfo(UniformHandle _handle, UniformInfo &_info) = 0;

        /// Destroy shader uniform parameter.
        ///
        /// @param[in] _handle Handle to uniform object.
        ///
        ///
        virtual void destroy(UniformHandle _handle) = 0;

        /// Create occlusion query.
        ///
        /// @returns Handle to occlusion query object.
        ///
        ///
        virtual OcclusionQueryHandle createOcclusionQuery() = 0;

        /// Retrieve occlusion query result from previous frame.
        ///
        /// @param[in] _handle Handle to occlusion query object.
        /// @param[out] _result Number of pixels that passed test. This argument
        ///   can be `NULL` if result of occlusion query is not needed.
        /// @returns Occlusion query result.
        ///
        ///
        virtual OcclusionQueryResult::Enum getResult(OcclusionQueryHandle _handle, int32_t *_result = NULL) = 0;

        /// Destroy occlusion query.
        ///
        /// @param[in] _handle Handle to occlusion query object.
        ///
        ///
        virtual void destroy(OcclusionQueryHandle _handle) = 0;

        /// Set palette color value.
        ///
        /// @param[in] _index Index into palette.
        /// @param[in] _rgba Packed 32-bit RGBA value.
        ///
        ///
        virtual void setPaletteColor(uint8_t _index, uint32_t _rgba) = 0;

        /// Set palette color value.
        ///
        /// @param[in] _index Index into palette.
        /// @param[in] _r, _g, _b, _a RGBA floating point values.
        ///
        ///
        virtual void setPaletteColor(uint8_t _index, float _r, float _g, float _b, float _a) = 0;

        /// Set palette color value.
        ///
        /// @param[in] _index Index into palette.
        /// @param[in] _rgba RGBA floating point value.
        ///
        ///
        virtual void setPaletteColor(uint8_t _index, const float _rgba[4]) = 0;

        /// Set view name.
        ///
        /// @param[in] _id View id.
        /// @param[in] _name View name.
        ///
        /// @remarks
        ///   This is debug only feature.
        ///
        ///   In graphics debugger view name will appear as:
        ///
        ///       "nnnce <view name>"
        ///        ^  ^^ ^
        virtual     ///        |  |+-- eye (L/R)
            virtual ///        |  +--- compute (C)
            ///        +------ view id
            ///
            ///
            virtual void
            setViewName(ViewId _id, const char *_name) = 0;

        /// Set view rectangle. Draw primitive outside view will be clipped.
        ///
        /// @param[in] _id View id.
        /// @param[in] _x Position x from the left corner of the window.
        /// @param[in] _y Position y from the top corner of the window.
        /// @param[in] _width Width of view port region.
        /// @param[in] _height Height of view port region.
        ///
        ///
        virtual void setViewRect(ViewId _id, uint16_t _x, uint16_t _y, uint16_t _width, uint16_t _height) = 0;

        /// Set view rectangle. Draw primitive outside view will be clipped.
        ///
        /// @param[in] _id View id.
        /// @param[in] _x Position x from the left corner of the window.
        /// @param[in] _y Position y from the top corner of the window.
        /// @param[in] _ratio Width and height will be set in respect to back-buffer size. See:
        ///   `BackbufferRatio::Enum`.
        ///
        ///
        virtual void setViewRect(ViewId _id, uint16_t _x, uint16_t _y, BackbufferRatio::Enum _ratio) = 0;

        /// Set view scissor. Draw primitive outside view will be clipped. When
        /// _x, _y, _width and _height are set to 0, scissor will be disabled.
        ///
        /// @param[in] _id View id.
        /// @param[in] _x Position x from the left corner of the window.
        /// @param[in] _y Position y from the top corner of the window.
        /// @param[in] _width Width of scissor region.
        /// @param[in] _height Height of scissor region.
        ///
        ///
        virtual void setViewScissor(ViewId _id, uint16_t _x = 0, uint16_t _y = 0, uint16_t _width = 0, uint16_t _height = 0) = 0;

        /// Set view clear flags.
        ///
        /// @param[in] _id View id.
        /// @param[in] _flags Clear flags. Use `ALT_GFX_CLEAR_NONE` to remove any clear
        ///   operation. See: `ALT_GFX_CLEAR_*`.
        /// @param[in] _rgba Color clear value.
        /// @param[in] _depth Depth clear value.
        /// @param[in] _stencil Stencil clear value.
        ///
        ///
        virtual void setViewClear(ViewId _id, uint16_t _flags, uint32_t _rgba = 0x000000ff, float _depth = 1.0f, uint8_t _stencil = 0) = 0;

        /// Set view clear flags with different clear color for each
        /// frame buffer texture. Must use `IGFX::setPaletteColor` to setup clear color
        /// palette.
        ///
        /// @param[in] _id View id.
        /// @param[in] _flags Clear flags. Use `ALT_GFX_CLEAR_NONE` to remove any clear
        ///   operation. See: `ALT_GFX_CLEAR_*`.
        /// @param[in] _depth Depth clear value.
        /// @param[in] _stencil Stencil clear value.
        /// @param[in] _0 Palette index for frame buffer attachment 0.
        /// @param[in] _1 Palette index for frame buffer attachment 1.
        /// @param[in] _2 Palette index for frame buffer attachment 2.
        /// @param[in] _3 Palette index for frame buffer attachment 3.
        /// @param[in] _4 Palette index for frame buffer attachment 4.
        /// @param[in] _5 Palette index for frame buffer attachment 5.
        /// @param[in] _6 Palette index for frame buffer attachment 6.
        /// @param[in] _7 Palette index for frame buffer attachment 7.
        ///
        ///
        virtual void setViewClear(ViewId _id, uint16_t _flags, float _depth, uint8_t _stencil, uint8_t _0 = UINT8_MAX, uint8_t _1 = UINT8_MAX, uint8_t _2 = UINT8_MAX, uint8_t _3 = UINT8_MAX, uint8_t _4 = UINT8_MAX, uint8_t _5 = UINT8_MAX, uint8_t _6 = UINT8_MAX, uint8_t _7 = UINT8_MAX) = 0;

        /// Set view sorting mode.
        ///
        /// @param[in] _id View id.
        /// @param[in] _mode View sort mode. See `ViewMode::Enum`.
        ///
        /// @remarks
        ///   View mode must be set prior calling `IGFX::submit` for the view.
        ///
        ///
        virtual void setViewMode(ViewId _id, ViewMode::Enum _mode = ViewMode::Default) = 0;

        /// Set view frame buffer.
        ///
        /// @param[in] _id View id.
        /// @param[in] _handle Frame buffer handle. Passing `ALT_GFX_INVALID_HANDLE` as
        ///   frame buffer handle will draw primitives from this view into
        ///   default back buffer.
        ///
        /// @remarks
        ///   Not persistent after `IGFX::reset` call.
        ///
        ///
        virtual void setViewFrameBuffer(ViewId _id, FrameBufferHandle _handle) = 0;

        /// Set view view and projection matrices, all draw primitives in this
        /// view will use these matrices.
        ///
        /// @param[in] _id View id.
        /// @param[in] _view View matrix.
        /// @param[in] _proj Projection matrix.
        ///
        ///
        virtual void setViewTransform(ViewId _id, const void *_view, const void *_proj) = 0;

        /// Post submit view reordering.
        ///
        /// @param[in] _id First view id.
        /// @param[in] _num Number of views to remap.
        /// @param[in] _remap View remap id table. Passing `NULL` will reset view ids
        ///   to default state.
        ///
        ///
        virtual void setViewOrder(ViewId _id = 0, uint16_t _num = UINT16_MAX, const ViewId *_remap = NULL) = 0;

        /// Reset all view settings to default.
        ///
        /// @param[in] _id View id.
        ///
        ///
        virtual void resetView(ViewId _id) = 0;

        /// Sets debug marker.
        ///
        ///
        virtual void setMarker(const char *_marker) = 0;

        /// Set render states for draw primitive.
        ///
        /// @param[in] _state State flags. Default state for primitive type is
        ///   triangles. See: `ALT_GFX_STATE_DEFAULT`.
        ///   - `ALT_GFX_STATE_DEPTH_TEST_*` - Depth test function.
        ///   - `ALT_GFX_STATE_BLEND_*` - See remark 1 about ALT_GFX_STATE_BLEND_FUNC.
        ///   - `ALT_GFX_STATE_BLEND_EQUATION_*` - See remark 2.
        ///   - `ALT_GFX_STATE_CULL_*` - Backface culling mode.
        ///   - `ALT_GFX_STATE_WRITE_*` - Enable R, G, B, A or Z write.
        ///   - `ALT_GFX_STATE_MSAA` - Enable MSAA.
        ///   - `ALT_GFX_STATE_PT_[TRISTRIP/LINES/POINTS]` - Primitive type.
        ///
        /// @param[in] _rgba Sets blend factor used by `ALT_GFX_STATE_BLEND_FACTOR` and
        ///   `ALT_GFX_STATE_BLEND_INV_FACTOR` blend modes.
        ///
        /// @remarks
        ///   1. To setup more complex states use:
        ///      `ALT_GFX_STATE_ALPHA_REF(_ref)`,
        ///      `ALT_GFX_STATE_POINT_SIZE(_size)`,
        ///      `ALT_GFX_STATE_BLEND_FUNC(_src, _dst)`,
        ///      `ALT_GFX_STATE_BLEND_FUNC_SEPARATE(_srcRGB, _dstRGB, _srcA, _dstA)`
        ///      `ALT_GFX_STATE_BLEND_EQUATION(_equation)`
        ///      `ALT_GFX_STATE_BLEND_EQUATION_SEPARATE(_equationRGB, _equationA)`
        ///   2. `ALT_GFX_STATE_BLEND_EQUATION_ADD` is set when no other blend
        ///      equation is specified.
        ///
        ///
        virtual void setState(uint64_t _state, uint32_t _rgba = 0) = 0;

        /// Set condition for rendering.
        ///
        /// @param[in] _handle Occlusion query handle.
        /// @param[in] _visible Render if occlusion query is visible.
        ///
        ///
        virtual void setCondition(OcclusionQueryHandle _handle, bool _visible) = 0;

        /// Set stencil test state.
        ///
        /// @param[in] _fstencil Front stencil state.
        /// @param[in] _bstencil Back stencil state. If back is set to `ALT_GFX_STENCIL_NONE`
        ///   _fstencil is applied to both front and back facing primitives.
        ///
        ///
        virtual void setStencil(uint32_t _fstencil, uint32_t _bstencil = ALT_GFX_STENCIL_NONE) = 0;

        /// Set scissor for draw primitive. For scissor for all primitives in
        /// view see `IGFX::setViewScissor`.
        ///
        /// @param[in] _x Position x from the left corner of the window.
        /// @param[in] _y Position y from the top corner of the window.
        /// @param[in] _width Width of scissor region.
        /// @param[in] _height Height of scissor region.
        /// @returns Scissor cache index.
        ///
        ///
        virtual uint16_t setScissor(uint16_t _x, uint16_t _y, uint16_t _width, uint16_t _height) = 0;

        /// Set scissor from cache for draw primitive.
        ///
        /// @param[in] _cache Index in scissor cache. Passing UINT16_MAX unset primitive
        ///   scissor and primitive will use view scissor instead.
        ///
        ///
        virtual void setScissor(uint16_t _cache = UINT16_MAX) = 0;

        /// Set model matrix for draw primitive. If it is not called,
        /// the model will be rendered with an identity model matrix.
        ///
        /// @param[in] _mtx Pointer to first matrix in array.
        /// @param[in] _num Number of matrices in array.
        /// @returns index into matrix cache in case the same model matrix has
        ///   to be used for other draw primitive call.
        ///
        ///
        virtual uint32_t setTransform(const void *_mtx, uint16_t _num = 1) = 0;

        /// Reserve `_num` matrices in internal matrix cache.
        ///
        /// @param[in] _transform Pointer to `Transform` structure.
        /// @param[in] _num Number of matrices.
        /// @returns index into matrix cache.
        ///
        /// @attention Pointer returned can be modifed until `IGFX::frame` is called.
        ///
        virtual uint32_t allocTransform(Transform *_transform, uint16_t _num) = 0;

        /// Set model matrix from matrix cache for draw primitive.
        ///
        /// @param[in] _cache Index in matrix cache.
        /// @param[in] _num Number of matrices from cache.
        ///
        ///
        virtual void setTransform(uint32_t _cache, uint16_t _num = 1) = 0;

        /// Set shader uniform parameter for draw primitive.
        ///
        /// @param[in] _handle Uniform.
        /// @param[in] _value Pointer to uniform data.
        /// @param[in] _num Number of elements. Passing `UINT16_MAX` will
        ///   use the _num passed on uniform creation.
        ///
        ///
        virtual void setUniform(UniformHandle _handle, const void *_value, uint16_t _num = 1) = 0;

        /// Set index buffer for draw primitive.
        ///
        /// @param[in] _handle Index buffer.
        ///
        ///
        virtual void setIndexBuffer(IndexBufferHandle _handle) = 0;

        /// Set index buffer for draw primitive.
        ///
        /// @param[in] _handle Index buffer.
        /// @param[in] _firstIndex First index to render.
        /// @param[in] _numIndices Number of indices to render.
        ///
        ///
        virtual void setIndexBuffer(IndexBufferHandle _handle, uint32_t _firstIndex, uint32_t _numIndices) = 0;

        /// Set index buffer for draw primitive.
        ///
        /// @param[in] _handle Dynamic index buffer.
        ///
        ///
        virtual void setIndexBuffer(DynamicIndexBufferHandle _handle) = 0;

        /// Set index buffer for draw primitive.
        ///
        /// @param[in] _handle Dynamic index buffer.
        /// @param[in] _firstIndex First index to render.
        /// @param[in] _numIndices Number of indices to render.
        ///
        ///
        virtual void setIndexBuffer(DynamicIndexBufferHandle _handle, uint32_t _firstIndex, uint32_t _numIndices) = 0;

        /// Set index buffer for draw primitive.
        ///
        /// @param[in] _tib Transient index buffer.
        ///
        ///
        virtual void setIndexBuffer(const TransientIndexBuffer *_tib) = 0;

        /// Set index buffer for draw primitive.
        ///
        /// @param[in] _tib Transient index buffer.
        /// @param[in] _firstIndex First index to render.
        /// @param[in] _numIndices Number of indices to render.
        ///
        ///
        virtual void setIndexBuffer(const TransientIndexBuffer *_tib, uint32_t _firstIndex, uint32_t _numIndices) = 0;

        /// Set vertex buffer for draw primitive.
        ///
        /// @param[in] _stream Vertex stream.
        /// @param[in] _handle Vertex buffer.
        ///
        ///
        virtual void setVertexBuffer(uint8_t _stream, VertexBufferHandle _handle) = 0;

        /// Set vertex buffer for draw primitive.
        ///
        /// @param[in] _stream Vertex stream.
        /// @param[in] _handle Vertex buffer.
        /// @param[in] _startVertex First vertex to render.
        /// @param[in] _numVertices Number of vertices to render.
        /// @param[in] _layoutHandle Vertex layout for aliasing vertex buffer. If invalid handle is
        ///   used, vertex layout used for creation of vertex buffer will be used.
        ///
        ///
        virtual void setVertexBuffer(uint8_t _stream, VertexBufferHandle _handle, uint32_t _startVertex, uint32_t _numVertices, VertexLayoutHandle _layoutHandle = ALT_GFX_INVALID_HANDLE) = 0;

        /// Set vertex buffer for draw primitive.
        ///
        /// @param[in] _stream Vertex stream.
        /// @param[in] _handle Dynamic vertex buffer.
        ///
        ///
        virtual void setVertexBuffer(uint8_t _stream, DynamicVertexBufferHandle _handle) = 0;

        /// Set vertex buffer for draw primitive.
        ///
        /// @param[in] _stream Vertex stream.
        /// @param[in] _handle Dynamic vertex buffer.
        /// @param[in] _startVertex First vertex to render.
        /// @param[in] _numVertices Number of vertices to render.
        /// @param[in] _layoutHandle Vertex layout for aliasing vertex buffer. If invalid handle is
        ///   used, vertex layout used for creation of vertex buffer will be used.
        ///
        ///
        virtual void setVertexBuffer(uint8_t _stream, DynamicVertexBufferHandle _handle, uint32_t _startVertex, uint32_t _numVertices, VertexLayoutHandle _layoutHandle = ALT_GFX_INVALID_HANDLE) = 0;

        /// Set vertex buffer for draw primitive.
        ///
        /// @param[in] _stream Vertex stream.
        /// @param[in] _tvb Transient vertex buffer.
        ///
        ///
        virtual void setVertexBuffer(uint8_t _stream, const TransientVertexBuffer *_tvb) = 0;

        /// Set vertex buffer for draw primitive.
        ///
        /// @param[in] _stream Vertex stream.
        /// @param[in] _tvb Transient vertex buffer.
        /// @param[in] _startVertex First vertex to render.
        /// @param[in] _numVertices Number of vertices to render.
        /// @param[in] _layoutHandle Vertex layout for aliasing vertex buffer. If invalid handle is
        ///   used, vertex layout used for creation of vertex buffer will be used.
        ///
        ///
        virtual void setVertexBuffer(uint8_t _stream, const TransientVertexBuffer *_tvb, uint32_t _startVertex, uint32_t _numVertices, VertexLayoutHandle _layoutHandle = ALT_GFX_INVALID_HANDLE) = 0;

        /// Set number of vertices for auto generated vertices use in conjuction
        /// with gl_VertexID.
        ///
        /// @param[in] _numVertices Number of vertices.
        ///
        /// @attention Availability depends on: `ALT_GFX_CAPS_VERTEX_ID`.
        ///
        virtual void setVertexCount(uint32_t _numVertices) = 0;

        /// Set instance data buffer for draw primitive.
        ///
        /// @param[in] _idb Transient instance data buffer.
        ///
        ///
        virtual void setInstanceDataBuffer(const InstanceDataBuffer *_idb) = 0;

        /// Set instance data buffer for draw primitive.
        ///
        /// @param[in] _idb Transient instance data buffer.
        /// @param[in] _start First instance data.
        /// @param[in] _num Number of data instances.
        ///
        ///
        virtual void setInstanceDataBuffer(const InstanceDataBuffer *_idb, uint32_t _start, uint32_t _num) = 0;

        /// Set instance data buffer for draw primitive.
        ///
        /// @param[in] _handle Vertex buffer.
        /// @param[in] _start First instance data.
        /// @param[in] _num Number of data instances.
        ///
        ///
        virtual void setInstanceDataBuffer(VertexBufferHandle _handle, uint32_t _start, uint32_t _num) = 0;

        /// Set instance data buffer for draw primitive.
        ///
        /// @param[in] _handle Vertex buffer.
        /// @param[in] _start First instance data.
        /// @param[in] _num Number of data instances.
        ///
        ///
        virtual void setInstanceDataBuffer(DynamicVertexBufferHandle _handle, uint32_t _start, uint32_t _num) = 0;

        /// Set number of instances for auto generated instances use in conjuction
        /// with gl_InstanceID.
        ///
        /// @param[in] _numInstances Number of instances.
        ///
        /// @attention Availability depends on: `ALT_GFX_CAPS_VERTEX_ID`.
        ///
        virtual void setInstanceCount(uint32_t _numInstances) = 0;

        /// Set texture stage for draw primitive.
        ///
        /// @param[in] _stage Texture unit.
        /// @param[in] _sampler Program sampler.
        /// @param[in] _handle Texture handle.
        /// @param[in] _flags Texture sampling mode. Default value UINT32_MAX uses
        ///   texture sampling settings from the texture.
        ///   - `ALT_GFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap
        ///     mode.
        ///   - `ALT_GFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic
        ///     sampling.
        ///
        ///
        virtual void setTexture(uint8_t _stage, UniformHandle _sampler, TextureHandle _handle, uint32_t _flags = UINT32_MAX) = 0;

        /// Submit an empty primitive for rendering. Uniforms and draw state
        /// will be applied but no geometry will be submitted.
        ///
        /// These empty draw calls will sort before ordinary draw calls.
        ///
        /// @param[in] _id View id.
        ///
        ///
        virtual void touch(ViewId _id) = 0;

        /// Submit primitive for rendering.
        ///
        /// @param[in] _id View id.
        /// @param[in] _program Program.
        /// @param[in] _depth Depth for sorting.
        /// @param[in] _flags Discard or preserve states. See `ALT_GFX_DISCARD_*`.
        ///
        ///
        virtual void submit(ViewId _id, ProgramHandle _program, uint32_t _depth = 0, uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

        /// Submit primitive with occlusion query for rendering.
        ///
        /// @param[in] _id View id.
        /// @param[in] _program Program.
        /// @param[in] _occlusionQuery Occlusion query.
        /// @param[in] _depth Depth for sorting.
        /// @param[in] _flags Discard or preserve states. See `ALT_GFX_DISCARD_*`.
        ///
        ///
        virtual void submit(ViewId _id, ProgramHandle _program, OcclusionQueryHandle _occlusionQuery, uint32_t _depth = 0, uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

        /// Submit primitive for rendering with index and instance data info from
        /// indirect buffer.
        ///
        /// @param[in] _id View id.
        /// @param[in] _program Program.
        /// @param[in] _indirectHandle Indirect buffer.
        /// @param[in] _start First element in indirect buffer.
        /// @param[in] _num Number of dispatches.
        /// @param[in] _depth Depth for sorting.
        /// @param[in] _flags Discard or preserve states. See `ALT_GFX_DISCARD_*`.
        ///
        ///
        virtual void submit(ViewId _id, ProgramHandle _program, IndirectBufferHandle _indirectHandle, uint16_t _start = 0, uint16_t _num = 1, uint32_t _depth = 0, uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

        /// Set compute index buffer.
        ///
        /// @param[in] _stage Compute stage.
        /// @param[in] _handle Index buffer handle.
        /// @param[in] _access Buffer access. See `Access::Enum`.
        ///
        ///
        virtual void setBuffer(uint8_t _stage, IndexBufferHandle _handle, Access::Enum _access) = 0;

        /// Set compute vertex buffer.
        ///
        /// @param[in] _stage Compute stage.
        /// @param[in] _handle Vertex buffer handle.
        /// @param[in] _access Buffer access. See `Access::Enum`.
        ///
        ///
        virtual void setBuffer(uint8_t _stage, VertexBufferHandle _handle, Access::Enum _access) = 0;

        /// Set compute dynamic index buffer.
        ///
        /// @param[in] _stage Compute stage.
        /// @param[in] _handle Dynamic index buffer handle.
        /// @param[in] _access Buffer access. See `Access::Enum`.
        ///
        ///
        virtual void setBuffer(uint8_t _stage, DynamicIndexBufferHandle _handle, Access::Enum _access) = 0;

        /// Set compute dynamic vertex buffer.
        ///
        /// @param[in] _stage Compute stage.
        /// @param[in] _handle Dynamic vertex buffer handle.
        /// @param[in] _access Buffer access. See `Access::Enum`.
        ///
        ///
        virtual void setBuffer(uint8_t _stage, DynamicVertexBufferHandle _handle, Access::Enum _access) = 0;

        /// Set compute indirect buffer.
        ///
        /// @param[in] _stage Compute stage.
        /// @param[in] _handle Indirect buffer handle.
        /// @param[in] _access Buffer access. See `Access::Enum`.
        ///
        ///
        virtual void setBuffer(uint8_t _stage, IndirectBufferHandle _handle, Access::Enum _access) = 0;

        /// Set compute image from texture.
        ///
        /// @param[in] _stage Texture unit.
        /// @param[in] _handle Texture handle.
        /// @param[in] _mip Mip level.
        /// @param[in] _access Texture access. See `Access::Enum`.
        /// @param[in] _format Texture format. See: `TextureFormat::Enum`.
        ///
        ///
        virtual void setImage(uint8_t _stage, TextureHandle _handle, uint8_t _mip, Access::Enum _access, TextureFormat::Enum _format = TextureFormat::Count) = 0;

        /// Dispatch compute.
        ///
        /// @param[in] _id View id.
        /// @param[in] _handle Compute program.
        /// @param[in] _numX Number of groups X.
        /// @param[in] _numY Number of groups Y.
        /// @param[in] _numZ Number of groups Z.
        /// @param[in] _flags Discard or preserve states. See `ALT_GFX_DISCARD_*`.
        ///
        ///
        virtual void dispatch(ViewId _id, ProgramHandle _handle, uint32_t _numX = 1, uint32_t _numY = 1, uint32_t _numZ = 1, uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

        /// Dispatch compute indirect.
        ///
        /// @param[in] _id View id.
        /// @param[in] _handle Compute program.
        /// @param[in] _indirectHandle Indirect buffer.
        /// @param[in] _start First element in indirect buffer.
        /// @param[in] _num Number of dispatches.
        /// @param[in] _flags Discard or preserve states. See `ALT_GFX_DISCARD_*`.
        ///
        ///
        virtual void dispatch(ViewId _id, ProgramHandle _handle, IndirectBufferHandle _indirectHandle, uint16_t _start = 0, uint16_t _num = 1, uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

        /// Discard all previously set state for draw or compute call.
        ///
        /// @param[in] _flags Draw/compute states to discard.
        ///
        ///
        virtual void discard(uint8_t _flags = ALT_GFX_DISCARD_ALL) = 0;

        /// Blit 2D texture region between two 2D textures.
        ///
        /// @param[in] _id View id.
        /// @param[in] _dst Destination texture handle.
        /// @param[in] _dstX Destination texture X position.
        /// @param[in] _dstY Destination texture Y position.
        /// @param[in] _src Source texture handle.
        /// @param[in] _srcX Source texture X position.
        /// @param[in] _srcY Source texture Y position.
        /// @param[in] _width Width of region.
        /// @param[in] _height Height of region.
        ///
        /// @attention Destination texture must be created with `ALT_GFX_TEXTURE_BLIT_DST` flag.
        /// @attention Availability depends on: `ALT_GFX_CAPS_TEXTURE_BLIT`.
        ///
        virtual void blit(ViewId _id, TextureHandle _dst, uint16_t _dstX, uint16_t _dstY, TextureHandle _src, uint16_t _srcX = 0, uint16_t _srcY = 0, uint16_t _width = UINT16_MAX, uint16_t _height = UINT16_MAX) = 0;

        /// Blit texture region between two textures.
        ///
        /// @param[in] _id View id.
        /// @param[in] _dst Destination texture handle.
        /// @param[in] _dstMip Destination texture mip level.
        /// @param[in] _dstX Destination texture X position.
        /// @param[in] _dstY Destination texture Y position.
        /// @param[in] _dstZ If texture is 2D this argument should be 0. If destination texture is cube
        ///   this argument represents destination texture cube face. For 3D texture this argument
        ///   represents destination texture Z position.
        /// @param[in] _src Source texture handle.
        /// @param[in] _srcMip Source texture mip level.
        /// @param[in] _srcX Source texture X position.
        /// @param[in] _srcY Source texture Y position.
        /// @param[in] _srcZ If texture is 2D this argument should be 0. If source texture is cube
        ///   this argument represents source texture cube face. For 3D texture this argument
        ///   represents source texture Z position.
        /// @param[in] _width Width of region.
        /// @param[in] _height Height of region.
        /// @param[in] _depth If texture is 3D this argument represents depth of region, otherwise it's
        ///   unused.
        ///
        /// @attention Destination texture must be created with `ALT_GFX_TEXTURE_BLIT_DST` flag.
        /// @attention Availability depends on: `ALT_GFX_CAPS_TEXTURE_BLIT`.
        ///
        virtual void blit(ViewId _id, TextureHandle _dst, uint8_t _dstMip, uint16_t _dstX, uint16_t _dstY, uint16_t _dstZ, TextureHandle _src, uint8_t _srcMip = 0, uint16_t _srcX = 0, uint16_t _srcY = 0, uint16_t _srcZ = 0, uint16_t _width = UINT16_MAX, uint16_t _height = UINT16_MAX, uint16_t _depth = UINT16_MAX) = 0;

        /// Request screen shot of window back buffer.
        ///
        /// @param[in] _handle Frame buffer handle. If handle is `ALT_GFX_INVALID_HANDLE` request will be
        ///   made for main window back buffer.
        /// @param[in] _filePath Will be passed to `IGFX::CallbackI::screenShot` callback.
        ///
        /// @remarks
        ///   `IGFX::CallbackI::screenShot` must be implemented.
        ///
        /// @attention Frame buffer handle must be created with OS' target native window handle.
        ///
        virtual void requestScreenShot(FrameBufferHandle _handle, const char *_filePath) = 0;
    };
} // namespace alt
