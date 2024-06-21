Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/focal64"
  config.vm.provider "virtualbox" do |vb|

    vb.memory = 4096
    vb.cpus = 2

  end

  config.vm.provision "shell", inline: <<-SHELL
    # Actualizar e instalar los paquetes esenciales
    sudo apt-get update
    sudo apt-get install -y build-essential git cmake

    # Instalar entorno de escritorio
    sudo apt-get install -y ubuntu-desktop

    # Instalar ALSA utils
    sudo apt-get install -y alsa-utils

    # Instalar SDL_image, SDL_mixer y SDL_ttf desde los repositorios
    sudo apt-get install -y libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev

    # Instalar dependencias de audio
    sudo apt-get install -y libasound2-dev libpulse-dev

    # Instalar yaml-cpp
    sudo apt-get install -y libyaml-cpp-dev

    # Clonar el repositorio de SDL
    git clone https://github.com/libsdl-org/SDL.git -b SDL2 /home/vagrant/SDL
    cd /home/vagrant/SDL

    # Compilar e instalar SDL
    mkdir build
    cd build
    cmake ..
    make
    sudo make install

    # Instalar gtest
    sudo apt-get install -y libgtest-dev
    cd /usr/src/gtest
    sudo cmake .
    sudo make
    sudo cp *.a /usr/lib

    # Instalar Qt5
    sudo apt-get install -y qt5-default qtbase5-dev qtdeclarative5-dev

    # Crear un directorio temporal dentro de la VM
    mkdir ~/project_copy

    # Copiar los archivos del proyecto a este nuevo directorio
    cp -r /vagrant/* ~/project_copy/
  SHELL

  config.vm.synced_folder ".", "/vagrant", disabled: false
end