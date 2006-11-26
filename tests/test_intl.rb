require 'test/unit'
require 'test/unit/ui/console/testrunner'
require 'wx'
class TestApp < Wx::App
  attr_accessor :test_class
  def on_init
    Test::Unit::UI::Console::TestRunner.run(self.test_class)
  end
end

class TestInternationalisation < Test::Unit::TestCase
  def test_encodings
    default = Wx::Font.get_default_encoding
    assert_kind_of(Integer, default)
    assert_kind_of(String, Wx::Font.get_default_encoding_name)
    assert_match(/\A[-A-Z0-9]+\z/, Wx::Font.get_default_encoding_name)

    Wx::Font.set_default_encoding(Wx::FONTENCODING_UTF8)
    assert_equal(Wx::FONTENCODING_UTF8, Wx::Font.get_default_encoding)
    assert_equal('UTF8', Wx::Font.get_default_encoding_name)

    Wx::Font.set_default_encoding(default)
    assert_equal(default, Wx::Font.get_default_encoding)

    Wx::Font.set_default_encoding_name('ISO-8859-1')
    assert_equal(Wx::FONTENCODING_ISO8859_1, Wx::Font.get_default_encoding)
    assert_equal('ISO-8859-1', Wx::Font.get_default_encoding_name)

    Wx::Font.set_default_encoding(default)
  end

  def test_language_info
    locale_info = Wx::Locale.find_language_info('en')
    assert_equal('English', locale_info.description)

    locale_info = Wx::Locale.find_language_info('pt_BR')
    assert_equal('Portuguese (Brazilian)', locale_info.description)

    locale_info = Wx::Locale.find_language_info('ja')
    assert_equal('Japanese', locale_info.description)

    assert_nil( Wx::Locale.find_language_info('xx') )
  end
  
  def test_add_language_info
    # FIXME - typemaps for wxString are not picked up when SWIG converts
    # the struct definition; so maybe do an %extend for this method that
    # accepts string canonical name and description and Win32
    # identifiers, and returns an integer id. See Locale.i
    language_marain = Wx::Locale.add_language('ma_MA', 'Marain',
                                               0, 0)
    assert_kind_of(Integer, language_marain)
    lang_info = Wx::Locale.find_language_info('ma_MA')
    assert_equal(Wx::LANGUAGE_MARAIN, lang_info.language)
    assert_equal('ma_MA', lang_info.canonical_name)
    assert_equal('Marain', lang_info.description)
  end

  def test_get_system_language
    sys_lang = Wx::Locale.get_system_language
    assert_kind_of(Fixnum, sys_lang)

    assert_kind_of(String, Wx::Locale.get_system_language_name)

    assert_kind_of(Integer, Wx::Locale.get_system_encoding)
    assert_kind_of(String, Wx::Locale.get_system_encoding_name)
    assert_match(/\A[-A-Z0-9]+\z/, Wx::Locale.get_system_encoding_name)
  end

  def test_set_locales
    time = Time.local(2006, 10, 25, 16, 48, 12)

    # setting via Locale.new
    locale = Wx::Locale.new(Wx::LANGUAGE_DANISH)
    assert_equal('da_DK', locale.get_canonical_name)
    assert_equal(Wx::LANGUAGE_DANISH, locale.get_language)
    assert_equal('Danish', locale.get_language_name)
    assert_equal('25.10.2006', time.strftime('%x'))

    # setting via Locale.set_locale
    locale = Wx::Locale.set_locale('en_GB')
    assert_equal('en_GB', locale.get_canonical_name)
    assert_equal(Wx::LANGUAGE_ENGLISH, locale.get_language)
    assert_equal('English', locale.get_language_name)
    assert_equal('25/10/2006', time.strftime('%x'))

    locale = Wx::Locale.set_locale('en_US')
    assert_equal('en_US', locale.get_canonical_name)
    assert_equal(Wx::LANGUAGE_ENGLISH_US, locale.get_language)
    assert_equal('English (U.S.)', locale.get_language_name)
    assert_equal('10/25/2006', time.strftime('%x'))

    assert_raises(ArgumentError) { Wx::Locale.set_locale('bad') }
    locale = Wx::Locale.new(Wx::LANGUAGE_DEFAULT)
  end
end

app = TestApp.new
app.test_class = TestInternationalisation
app.main_loop
