/*
 * Copyright (c) 2015 peeracle contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef PEERACLE_PEER_PEERINTERFACE_H_
#define PEERACLE_PEER_PEERINTERFACE_H_

#include <string>

namespace peeracle {

class PeerInterface {
 public:
  class Observer {
   public:
    virtual void onIceCandidate(const std::string &sdpMid,
                                int sdpMLineIndex,
                                const std::string &candidate) = 0;
    virtual void onSignalingChange(int state) = 0;
    virtual void onStateChange(int state) = 0;
    virtual void onIceConnectionChange(int state) = 0;
    virtual void onIceGatheringChange(int state) = 0;

   protected:
    virtual ~Observer() {}
  };

  class CreateSDPObserver {
   public:
    virtual void onSuccess(const std::string &sdp,
                           const std::string &type) = 0;
    virtual void onFailure(const std::string &error) = 0;

   protected:
    ~CreateSDPObserver() {}
  };

  class SetSDPObserver {
   public:
    virtual void onSuccess() = 0;
    virtual void onFailure(const std::string &error) = 0;

   protected:
    ~SetSDPObserver() {}
  };

  virtual const std::string &getId() const = 0;

  virtual ~PeerInterface() {}
};

}  // namespace peeracle

#endif  // PEERACLE_PEER_PEERINTERFACE_H_
