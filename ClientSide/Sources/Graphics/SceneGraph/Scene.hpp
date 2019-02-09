/*
 * Copyright 2018 Vladimir Balun
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Node.hpp"
#include "SceneGraphBuilder.hpp"
#include "../OpenGL.hpp"
#include "../Managers/MeshManager.hpp"
#include "../Managers/ShaderManager.hpp"
#include "../../Math/Matrices.hpp"
#include "../../Memory/LinearAllocator.hpp"

namespace Graphics { namespace SceneGraph {

    class Scene
    {
    public:
        explicit Scene(HDC& windowContext)
            : mWindowContext(windowContext), mSceneGraphAllocator(ONE_VIRTUAL_PAGE) {}
        GLvoid init(GLint sceneWidth, GLint sceneHeight);
        GLvoid render();
        GLvoid update();
    private:
        Node* mRootNode = nullptr;
        HDC& mWindowContext;
        Math::Matrix4x4f mViewMatrix;
        Math::Matrix4x4f mPerspectiveMatrix;
        Managers::MeshManager mMeshManager;
        Managers::ShaderManager mShaderManager;
        Memory::LinearAllocator mSceneGraphAllocator;
    };

}}
