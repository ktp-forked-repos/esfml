////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2013 Jonathan De Wachter (dewachter.jonathan@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Video/VideoSource.hpp>
#include <SFML/Video/VideoPlayer.hpp>
#include <SFML/Graphics/Sprite.hpp>


namespace sf
{
////////////////////////////////////////////////////////////
VideoSource::VideoSource()
: m_player(new priv::VideoPlayer)
{
	// todo: ensure FFMPEG is loaded ?
}


////////////////////////////////////////////////////////////
VideoSource::VideoSource(const VideoSource& copy)
{
    // todo: should we do something here ?
}


////////////////////////////////////////////////////////////
VideoSource::~VideoSource()
{
    delete m_player;
}


////////////////////////////////////////////////////////////
VideoSource::Status VideoSource::getStatus() const
{
    return m_player->getStatus();
}


////////////////////////////////////////////////////////////
void VideoSource::draw(RenderTarget& target, RenderStates states) const
{
    // Grab the current frame
    Sprite frame(m_player->getCurrentFrame());

    // Apply the video render states
    states.transform *= getTransform();

    // Draw the current frame
    target.draw(frame, states);
}

} // namespace sf
