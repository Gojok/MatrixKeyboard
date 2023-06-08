/**
 ******************************************************************************
 * @file    MatrixKeyboard.hpp
 * @date    07-06-2023
 * @author  Gojok
 ******************************************************************************
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************
 */

#pragma once

#include <stdint.h>
#include <vector>
#include "IGpio.hpp"
#include "IListener.hpp"

namespace Hardware {

class MatrixKeyboard : public Interfaces::IGpitEvent
{
public:

    enum class Event {
        kPressed,
        kReleased,
    };

    typedef struct{
        uint8_t rowNumber;
        uint8_t columnNumber;
        Event
    }Key_t;


    
    MatrixKeyboard(std::vector<Interfaces::IGpo*> &row, std::vector<Interfaces::IGpi*> &column);

    MatrixKeyboard(std::vector<Interfaces::IGpo*> &row, std::vector<Interfaces::IGpit*> &column);

    ~MatrixKeyboard();

    void setListner(Interfaces::IListener &listener);

    void update();

    std::vector<Key_t> getKey();

    void onChange(Interfaces::IGpit *pGpit) override;

private:
    std::vector<Interfaces::IGpi*> *mpGpi;
    std::vector<Interfaces::IGpit*> *mpGpit;
    Interfaces::IListener *mpListener
};

} //namespace Hardware

