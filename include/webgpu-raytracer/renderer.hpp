#pragma once

#include <webgpu-raytracer/shader_registry.hpp>
#include <webgpu-raytracer/scene_data.hpp>
#include <webgpu-raytracer/camera.hpp>

#include <webgpu.h>

#include <memory>

struct Renderer
{
    Renderer(WGPUDevice device, WGPUQueue queue, WGPUTextureFormat surfaceFormat, ShaderRegistry & shaderRegistry);
    ~Renderer();

    void renderFrame(WGPUTexture surfaceTexture, Camera const & camera, SceneData const & sceneData);

private:
    struct Impl;
    std::unique_ptr<Impl> pimpl_;
};
