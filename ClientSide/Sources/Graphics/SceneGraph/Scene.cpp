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

#include "Scene.hpp"

GLvoid Graphics::SceneGraph::Scene::init(GLint sceneWidth, GLint sceneHeight)
{
    mShaderManager.initializeShaders();
    mMeshManager.initializeMeshes();

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.3f, 0.7f, 0.9f, 1.0f);
    glViewport(0, 0, sceneWidth, sceneHeight);

    // TODO: need to add class for camera
    Math::setLookAt(mViewMatrix, { 0.0f, 0.0f, 3.0f }, { 0.0f, 0.0f, 2.0f }, { 0.0f, 1.0f, 0.0f });
    Math::setPerspectiveMatrix(mPerspectiveMatrix, 45.0f, (GLfloat) sceneWidth / sceneHeight, 0.1f, 100.f);

    mRootNode = SceneGraphBuilder::build(mMeshManager, mSceneGraphAllocator);
}

GLvoid Graphics::SceneGraph::Scene::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Tools::ShaderProgram& shader = mShaderManager.getShader(Managers::BASE_SHADER);
    shader.use();

    if (mRootNode->isExistChildren()) 
    {
        mRootNode->childrenForEach([&shader](Node* child)
        {
            if (child->isExistMesh()) 
            {
                shader.setUniformMatrix("modelMatrix", child->getTransformation());
                child->getMesh().draw();
            }
        });
    }

    glFinish();
    SwapBuffers(mWindowContext);
}

GLvoid Graphics::SceneGraph::Scene::update()
{

}
