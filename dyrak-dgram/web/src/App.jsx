import React, { useState, useEffect } from 'react';
import { 
  MdHome, 
  MdChat, 
 MdPeople, 
  MdSettings, 
  MdSearch,
  MdMenu,
  MdClose,
  MdDarkMode,
  MdLightMode,
  MdPhone,
  MdDesktopWindows
} from 'react-icons/md';

function App() {
  const [darkMode, setDarkMode] = useState(true);
  const [sidebarOpen, setSidebarOpen] = useState(false);
  const [activeTab, setActiveTab] = useState('home');

  const toggleSidebar = () => setSidebarOpen(!sidebarOpen);

  const renderContent = () => {
    switch (activeTab) {
      case 'home':
        return <HomeSection />;
      case 'chat':
        return <ChatSection />;
      case 'people':
        return <PeopleSection />;
      case 'settings':
        return <SettingsSection darkMode={darkMode} setDarkMode={setDarkMode} />;
      default:
        return <HomeSection />;
    }
  };

  return (
    <div className={`flex h-screen ${darkMode ? 'dark bg-gray-900' : 'bg-gray-50'}`}>
      {/* Sidebar */}
      <aside className={`${sidebarOpen ? 'block' : 'hidden'} md:block w-64 bg-sidebar dark:bg-sidebar flex-shrink-0`}>
        <div className="p-4">
          <h1 className="text-2xl font-bold text-white">dyrakDGram</h1>
          <p className="text-gray-500 text-sm">Telegram Client v2.0</p>
        </div>
        
        <nav className="mt-4">
          <SidebarItem 
            icon={<MdHome />} 
            text="Начало" 
            active={activeTab === 'home'} 
            onClick={() => { setActiveTab('home'); setSidebarOpen(false); }} 
          />
          <SidebarItem 
            icon={<MdChat />} 
            text="Съобщения" 
            active={activeTab === 'chat'} 
            onClick={() => { setActiveTab('chat'); setSidebarOpen(false); }} 
          />
          <SidebarItem 
            icon={<MdPeople />} 
            text="Хора" 
            active={activeTab === 'people'} 
            onClick={() => { setActiveTab('people'); setSidebarOpen(false); }} 
          />
          <SidebarItem 
            icon={<MdSettings />} 
            text="Настройки" 
            active={activeTab === 'settings'} 
            onClick={() => { setActiveTab('settings'); setSidebarOpen(false); }} 
          />
        </nav>
        
        <div className="mt-auto p-4">
          <DeviceTypeIndicator darkMode={darkMode} />
        </div>
      </aside>

      {/* Main Content */}
      <main className="flex-1 flex flex-col h-screen overflow-hidden">
        {/* Header */}
        <header className="bg-white dark:bg-gray-800 border-b dark:border-gray-700 p-4 flex items-center justify-between">
          <div className="flex items-center md:hidden">
            <button 
              onClick={toggleSidebar}
              className="text-gray-600 dark:text-white p-2"
            >
              {sidebarOpen ? <MdClose size={24} /> : <MdMenu size={24} />}
            </button>
          </div>
          
          <h1 className="text-xl font-semibold text-gray-800 dark:text-white hidden md:block">
            dyrakDGram
          </h1>
          
          <div className="flex items-center space-x-4">
            <button 
              onClick={() => setDarkMode(!darkMode)}
              className="p-2 rounded-full bg-gray-200 dark:bg-gray-700 text-gray-800 dark:text-white hover:bg-gray-300 dark:hover:bg-gray-600 transition-colors"
            >
              {darkMode ? <MdLightMode size={24} /> : <MdDarkMode size={24} />}
            </button>
            
            <button className="p-2 rounded-full bg-blue-100 dark:bg-blue-900 text-blue-600 dark:text-blue-300">
              <MdSearch size={24} />
            </button>
          </div>
        </header>

        {/* Content Area */}
        <div className="flex-1 overflow-auto p-4 md:p-6 lg:p-8">
          {renderContent()}
        </div>
      </main>

      {/* Mobile Sidebar Overlay */}
      {sidebarOpen && (
        <div 
          className="fixed inset-0 bg-black bg-opacity-50 z-40 md:hidden"
          onClick={() => setSidebarOpen(false)}
        ></div>
      )}
    </div>
  );
}

// Sub-components
function SidebarItem({ icon, text, active, onClick }) {
  return (
    <button
      onClick={onClick}
      className={`w-full flex items-center p-3 rounded-lg transition-colors ${
        active 
          ? 'bg-blue-600 text-white' 
          : 'text-gray-700 dark:text-gray-300 hover:bg-gray-200 dark:hover:bg-gray-700'
      }`}
    >
      <span className="text-xl mr-3">{icon}</span>
      <span>{text}</span>
    </button>
  );
}

function DeviceTypeIndicator({ darkMode }) {
  return (
    <div className={`p-4 rounded-lg ${darkMode ? 'bg-gray-800' : 'bg-gray-200'}`}>
      <h3 className={`font-semibold mb-2 ${darkMode ? 'text-white' : 'text-gray-900'}`}>
        Device Type
      </h3>
      <div className="flex items-center justify-between">
        <span className="text-sm">Platform:</span>
        <span className="font-medium text-blue-600">Web/Desktop</span>
      </div>
      <div className="flex items-center justify-between mt-2">
        <span className="text-sm">Version:</span>
        <span className="font-medium">2.0.0</span>
      </div>
    </div>
  );
}

function HomeSection() {
  return (
    <div className="max-w-6xl mx-auto">
      <div className="text-center py-12">
        <h1 className="text-4xl md:text-5xl font-bold mb-6 bg-gradient-to-r from-blue-600 to-purple-600 bg-clip-text text-transparent">
          Welcome to dyrakDGram
        </h1>
        <p className="text-xl text-gray-600 dark:text-gray-300 mb-8">
          Your personalized Telegram client with enhanced features.
        </p>
        
        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6">
          <FeatureCard 
            title="Минималистичен интерфейс" 
            description="Оптимизиран дизайн за максимална продуктивност." 
            icon={<MdHome size={40} />}
          />
          <FeatureCard 
            title="Съобщения" 
            description="Бързи и сигурни съобщения с вашите приятели." 
            icon={<MdChat size={40} />}
          />
          <FeatureCard 
            title="Потребители" 
            description="Управление на вашите контакти и групи." 
            icon={<MdPeople size={40} />}
          />
        </div>
      </div>

      <div className="max-w-3xl mx-auto mt-12">
        <h2 className="text-2xl font-bold mb-6 dark:text-white">Latest Updates</h2>
        <UpdateList />
      </div>
    </div>
  );
}

function ChatSection() {
  return (
    <div className="max-w-5xl mx-auto">
      <div className="bg-white dark:bg-gray-800 rounded-xl shadow-lg p-6 mb-6">
        <h2 className="text-2xl font-bold mb-4 dark:text-white">Съобщения</h2>
        <p className="text-gray-600 dark:text-gray-300">
          Your Telegram messages will be displayed here with enhanced features including:
        </p>
        <ul className="mt-4 space-y-2 text-gray-600 dark:text-gray-300">
          <li>• Ускорени съобщения чрез плъгини</li>
          <li>• Специални функции за визуализация</li>
          <li>• Интегриране с вашия личен домейн</li>
        </ul>
      </div>

      <div className="grid grid-cols-1 md:grid-cols-2 gap-6 mt-8">
        <MessageCard 
          avatar="https://placehold.co/100x100/0088cc/white"
          name="Теодосия Тодорова"
          message="Привет! Какво ново?"
          time="10:30"
          unread={true}
        />
        <MessageCard 
          avatar="https://placehold.co/100x100/2563eb/white"
          name="Група: Разработчици"
          message="Новата версия е готова!"
          time="09:15"
          unread={false}
        />
      </div>
    </div>
  );
}

function PeopleSection() {
  return (
    <div className="max-w-5xl mx-auto">
      <h2 className="text-2xl font-bold mb-6 dark:text-white">Вашия контакти</h2>
      
      <div className="mb-6">
        <input 
          type="text" 
          placeholder="Търси в контакти..." 
          className="w-full px-4 py-3 rounded-lg bg-gray-100 dark:bg-gray-700 text-gray-900 dark:text-white border-none focus:ring-2 focus:ring-blue-500"
        />
      </div>

      <ContactList />
    </div>
  );
}

function SettingsSection({ darkMode, setDarkMode }) {
  return (
    <div className="max-w-4xl mx-auto">
      <h2 className="text-2xl font-bold mb-6 dark:text-white">Настройки</h2>
      
      <div className="space-y-6">
        <SettingsCard title="Общо" icon={<MdDesktopWindows size={24} />}>
          <p className="text-gray-600 dark:text-gray-300 mb-4">
            Основни настройки за вашето устройство.
          </p>
        </SettingsCard>

        <SettingsCard title="Тъмна тема" icon={<MdDarkMode size={24} />}>
          <div className="flex items-center justify-between mt-4">
            <span className="text-gray-600 dark:text-gray-300">Превключи тъмна тема</span>
            <button
              onClick={() => setDarkMode(!darkMode)}
              className={`relative inline-flex h-8 w-14 items-center rounded-full transition-colors ${
                darkMode ? 'bg-blue-600' : 'bg-gray-300'
              }`}
            >
              <span 
                className={`inline-block h-6 w-6 transform rounded-full bg-white transition-transform ${
                  darkMode ? 'translate-x-7' : 'translate-x-1'
                }`}
              />
            </button>
          </div>
        </SettingsCard>

        <SettingsCard title="Версия" icon={<MdPhone size={24} />}>
          <div className="mt-4">
            <p className="text-sm text-gray-500">dyrakDGram v2.0.0</p>
            <p className="text-sm text-gray-500 mt-1">Десктоп версия</p>
          </div>
        </SettingsCard>
      </div>
    </div>
  );
}

// Helper components
function FeatureCard({ title, description, icon }) {
  return (
    <div className="bg-white dark:bg-gray-800 p-6 rounded-xl shadow-lg text-center hover:shadow-xl transition-shadow">
      <div className="mx-auto w-16 h-16 bg-blue-100 dark:bg-blue-900 rounded-full flex items-center justify-center mb-4">
        {icon}
      </div>
      <h3 className="text-xl font-semibold mb-2 dark:text-white">{title}</h3>
      <p className="text-gray-600 dark:text-gray-300">{description}</p>
    </div>
  );
}

function UpdateList() {
  const updates = [
    { date: 'Преди 1 час', title: 'Нова функционалност', description: 'Добавени са нови плъгини за подобряване.' },
    { date: 'Вчера', title: 'Подобрения в производителността', description: 'Оптимизиране на скоростта на зареждане.' },
    { date: 'Преди 2 дни', title: 'Обновен интерфейс', description: 'Актуализиран дизайна за по-добра употреба.' },
  ];

  return (
    <div className="space-y-4">
      {updates.map((update, i) => (
        <div key={i} className="flex items-start p-4 bg-gray-50 dark:bg-gray-800 rounded-lg">
          <div className="flex-shrink-0 mt-1 text-blue-600">
            <MdChat size={20} />
          </div>
          <div className="ml-3">
            <p className="text-sm font-medium text-gray-900 dark:text-white">{update.title}</p>
            <p className="text-sm text-gray-500">{update.date}</p>
            <p className="mt-1 text-sm text-gray-600 dark:text-gray-300">{update.description}</p>
          </div>
        </div>
      ))}
    </div>
  );
}

function MessageCard({ avatar, name, message, time, unread }) {
  return (
    <div className={`flex items-center p-4 rounded-lg cursor-pointer transition-colors ${
      unread 
        ? 'bg-blue-50 dark:bg-blue-900/20 border-l-4 border-blue-600' 
        : 'hover:bg-gray-100 dark:hover:bg-gray-700'
    }`}>
      <img src={avatar} alt={name} className="w-12 h-12 rounded-full mr-4" />
      <div className="flex-1">
        <h3 className="font-semibold text-gray-900 dark:text-white">{name}</h3>
        <p className={`text-sm ${unread ? 'text-blue-600 font-medium' : 'text-gray-600 dark:text-gray-400'}`}>
          {message}
        </p>
      </div>
      <span className="text-xs text-gray-500">{time}</span>
    </div>
  );
}

function ContactList() {
  const contacts = [
    { name: 'Теодосия Тодорова', status: 'На линия', avatar: 'https://placehold.co/100x100/0088cc/white' },
    { name: 'Група: Приятели', status: 'Групово съобщение', avatar: 'https://placehold.co/100x100/2563eb/white' },
    { name: 'Иван Иванов', status: 'Блокиран', avatar: 'https://placehold.co/100x100/666666/white' },
    { name: 'Мария Петрова', status: 'Офлайн', avatar: 'https://placehold.co/100x100/cccccc/white' },
    { name: 'Група: Работа', status: '5 непрочетени', avatar: 'https://placehold.co/100x100/007bff/white' },
  ];

  return (
    <div className="space-y-3">
      {contacts.map((contact, i) => (
        <ContactItem key={i} contact={contact} />
      ))}
    </div>
  );
}

function ContactItem({ contact }) {
  return (
    <div className="flex items-center p-3 bg-white dark:bg-gray-800 rounded-lg hover:bg-gray-50 dark:hover:bg-gray-700 transition-colors">
      <img 
        src={contact.avatar} 
        alt={contact.name} 
        className="w-12 h-12 rounded-full mr-4 object-cover"
      />
      <div>
        <h4 className="font-semibold text-gray-900 dark:text-white">{contact.name}</h4>
        <p className="text-sm text-gray-600 dark:text-gray-400">{contact.status}</p>
      </div>
    </div>
  );
}

function SettingsCard({ title, icon, children }) {
  return (
    <div className="bg-white dark:bg-gray-800 rounded-xl shadow-lg p-6">
      <div className="flex items-start mb-4">
        <div className="p-3 bg-blue-100 dark:bg-blue-900 rounded-lg mr-4">
          {icon}
        </div>
        <div>
          <h3 className="text-xl font-semibold dark:text-white">{title}</h3>
          <p className="text-gray-600 dark:text-gray-400 text-sm mt-1">
            Управление на вашите предпочитания
          </p>
        </div>
      </div>
      {children}
    </div>
  );
}

export default App;
